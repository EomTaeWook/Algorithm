using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.Sort
{
    class ColumnSort
    {
        public static int[,] Sort(int[,] unSortList)
        {
            Sort(ref unSortList);
            Transposed(ref unSortList);
            Sort(ref unSortList);
            ReverseTransposed(ref unSortList);
            Sort(ref unSortList);
            int[,] transposedMatrix = null;
            HalfDivideTransposed(ref unSortList, out transposedMatrix);
            ReverseHalfDivideTransposed(ref transposedMatrix, out unSortList);
            return unSortList;
        }
        private static void Sort(ref int[,] unSortList)
        {
            if (unSortList.Length > 0 && (unSortList.GetLength(0) & 1) == 0)
            {
                for (int i = 0; i < unSortList.GetLength(1); i++)
                {
                    for (int ii = 0; ii < unSortList.GetLength(0); ii++)
                    {
                        for (int iii = 1; iii < unSortList.GetLength(0); iii++)
                        {
                            if (unSortList[iii, i] < unSortList[iii - 1, i])
                            {
                                Swap(ref unSortList, i, iii, i, iii - 1);
                            }
                        }
                    }
                }
            }
        }
        private static void Sort(ref int[,] unSortList, int begin, int end)
        {
            for (int i = begin; i < end; i++)
            {
                for (int ii = 0; ii < unSortList.GetLength(0); ii++)
                {
                    for (int iii = 1; iii < unSortList.GetLength(0); iii++)
                    {
                        if (unSortList[iii, i] < unSortList[iii - 1, i])
                        {
                            Swap(ref unSortList, i, iii, i, iii - 1);
                        }
                    }
                }
            }
        }
        private static void ReverseHalfDivideTransposed(ref int[,] unSortList, out int[,] sortList)
        {
            sortList = new int[unSortList.GetLength(0), unSortList.GetLength(1) - 1];
            int row = unSortList.GetLength(0) / 2;
            for (int i = 0; i < row; i++)
            {
                for (int ii = 0; ii < unSortList.GetLength(1) - 1; ii++)
                {
                    sortList[i, ii] = unSortList[i + row, ii];
                }
                for (int ii = 1; ii < unSortList.GetLength(1); ii++)
                {
                    sortList[row + i, ii - 1] = unSortList[i, ii];
                }
            }
        }
        private static void HalfDivideTransposed(ref int[,] unSortList, out int[,] transposedMatrix)
        {
            transposedMatrix = new int[unSortList.GetLength(0), unSortList.GetLength(1) + 1];
            int row = unSortList.GetLength(0) / 2;
            for (int i = 0; i < row; i++)
            {
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[row + i, ii] = unSortList[i, ii];
                }
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[i, ii + 1] = unSortList[row + i, ii];
                }
            }
            Sort(ref transposedMatrix, 1, transposedMatrix.GetLength(1) - 1);
        }
        public class GoogleJsonWebToken
        {
            private const string SCOPE_AUTH_ANDROIDPUBLISHER = @"https://www.googleapis.com/auth/androidpublisher";
            public static dynamic GetAccessToken()
            {
                // header
                var header = new { typ = "JWT", alg = "RS256" };
                var times = GetExpiryAndIssueDate();
                var claimset = new
                {
                    iss = "gather-heroes@api-",
                    scope = SCOPE_AUTH_ANDROIDPUBLISHER,
                    aud = @"https://accounts.google.com/o/oauth2/token",
                    iat = times[0],
                    exp = times[1],
                };
                JavaScriptSerializer ser = new JavaScriptSerializer();
                // encoded header
                var headerSerialized = ser.Serialize(header);
                var headerBytes = Encoding.UTF8.GetBytes(headerSerialized);
                var headerEncoded = Base64UrlEncode(headerBytes);
                ///////////////
                ///certificate
                ////////////////            
                byte[] dataKey = null;
                using (var stream = System.Reflection.Assembly.GetExecutingAssembly().GetManifestResourceStream("ProjectNameSpace. Resources.Google.Play.Android.Developer-906baXXXX.p12"))
                {
                    dataKey = new byte[stream.Length];
                    stream.Read(dataKey, 0, dataKey.Length);
                }
                X509Certificate2 certificate = new X509Certificate2(dataKey, "notasecret");
                // encoded claimset
                var claimsetSerialized = ser.Serialize(claimset);
                var claimsetBytes = Encoding.UTF8.GetBytes(claimsetSerialized);
                var claimsetEncoded = Base64UrlEncode(claimsetBytes);
                // input
                var input = headerEncoded + "." + claimsetEncoded;
                var inputBytes = Encoding.UTF8.GetBytes(input);
                // signiture
                var rsa = certificate.PrivateKey as RSACryptoServiceProvider;
                var cspParam = new CspParameters
                {
                    KeyContainerName = rsa.CspKeyContainerInfo.KeyContainerName,
                    KeyNumber = rsa.CspKeyContainerInfo.KeyNumber == KeyNumber.Exchange ? 1 : 2
                };
                var aescsp = new RSACryptoServiceProvider(cspParam) { PersistKeyInCsp = false };
                var signatureBytes = aescsp.SignData(inputBytes, "SHA256");
                var signatureEncoded = Base64UrlEncode(signatureBytes);
                // jwt
                var jwt = headerEncoded + "." + claimsetEncoded + "." + signatureEncoded;
                var client = new WebClient();
                client.Encoding = Encoding.UTF8;
                var uri = @"https://accounts.google.com/o/oauth2/token";
                var content = new NameValueCollection();
                content["assertion"] = jwt;
                content["grant_type"] = "urn:ietf:params:oauth:grant-type:jwt-bearer";
                string response = Encoding.UTF8.GetString(client.UploadValues(uri, "POST", content));
                var result = ser.Deserialize<dynamic>(response);
                return result;
            }
            private static int[] GetExpiryAndIssueDate()
            {
                var utc0 = new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc);
                var issueTime = DateTime.UtcNow;
                var iat = (int)issueTime.Subtract(utc0).TotalSeconds;
                var exp = (int)issueTime.AddMinutes(55).Subtract(utc0).TotalSeconds;
                return new[] { iat, exp };
            }
            private static string Base64UrlEncode(byte[] input)
            {
                var output = Convert.ToBase64String(input);
                output = output.Split('=')[0]; // Remove any trailing '='s
                output = output.Replace('+', '-'); // 62nd char of encoding
                output = output.Replace('/', '_'); // 63rd char of encoding
                return output;
            }

        }
        private static void Transposed(ref int[,] unSortList)
        {
            var auth = GoogleJsonWebToken.GetAccessToken();
            string url = $@"https://www.googleapis.com/androidpublisher/v2/applications/"+$"{this.Params["appid"]}/purchases/products/{this.Params["productid"]}/tokens/{this.Params["token"]}?access_token={auth["access_token"]}";
            System.Net.Http.HttpClient client = new System.Net.Http.HttpClient();
            client.DefaultRequestHeaders.Accept.Add(new System.Net.Http.Headers.MediaTypeWithQualityHeaderValue("application/json"));
            var req = client.GetAsync(new Uri(url));
            try
            {
                if(req.Result.IsSuccessStatusCode)
                {

                }
            }
            catch
            {
            }
            if (req.Result.IsSuccessStatusCode)
            {
                var result = req.Result.Content.ReadAsStringAsync().Result;
                Receipt _result = JsonConvert.DeserializeObject<Receipt>(result);
                if (_result.PurchaseState == 0)
                {
                    /*

                    아이템 지급 및 로그 기록

                    */
                }
            }
            else
            {
            }
            catch (Exception ex)
            {
            }
        }
            
}

    var transposedMatrix = new int[unSortList.GetLength(0), unSortList.GetLength(1)];
            int row = 0, col = 0;
            for (int i = 0; i < unSortList.GetLength(0); i++)
            {
                if (i != 0 && (i & 1) == 0)
                {
                    row = 0;
                    col++;
                }
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[i, ii] = unSortList[row++, col];
                }
            }
            Array.Copy(transposedMatrix, unSortList, transposedMatrix.Length);
        }

        private static void ReverseTransposed(ref int[,] unSortList)
        {
            var transposedMatrix = new int[unSortList.GetLength(0), unSortList.GetLength(1)];
            int row = 0, col = 0;
            for (int i = 0; i < unSortList.GetLength(0); i++)
            {
                if (i != 0 && (i & 1) == 0)
                {
                    row = 0;
                    col++;
                }
                for (int ii = 0; ii < unSortList.GetLength(1); ii++)
                {
                    transposedMatrix[row++, col] = unSortList[i, ii];
                }
            }
            Array.Copy(transposedMatrix, unSortList, transposedMatrix.Length);
        }
        private static void Swap(ref int[,] unSortList, int a_x, int a_y, int b_x, int b_y)
        {
            var temp = unSortList[a_y, a_x];
            unSortList[a_y, a_x] = unSortList[b_y, b_x];
            unSortList[b_y, b_x] = temp;
        }
    }
}
