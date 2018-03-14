using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.Observer
{
    interface IObserver
    {
        void Notify(EventArgs args);
    }
}
