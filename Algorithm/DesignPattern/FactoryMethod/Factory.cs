using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.FactoryMethod
{
    class Factory
    {
        public enum CallbackType
        {
            CallbackA,
            CallbackB
        }
        public ICallback Create(CallbackType type)
        {
            switch (type)
            {
                case CallbackType.CallbackA:
                    return new CallbackA();
                case CallbackType.CallbackB:
                    return new CallbackB();
                default:
                    throw new System.TypeAccessException();
            }
        }
    }
}
