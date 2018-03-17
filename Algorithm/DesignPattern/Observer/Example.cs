using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.Observer
{
    class ConcreateObserverA : DesignPattern.Observer.IObserver
    {
        public void Notify(EventArgs args)
        {
            Console.WriteLine("ConcreateObserverA");
        }
    }
    class ConcreateObserverB : DesignPattern.Observer.IObserver
    {
        public void Notify(EventArgs args)
        {
            Console.WriteLine("ConcreateObserverB");
        }
    }
    class Example
    {
        void Main()
        {
            DesignPattern.Observer.Subject subject = new DesignPattern.Observer.Subject();

            ConcreateObserverA concreateObserverA = new ConcreateObserverA();
            ConcreateObserverB concreateObserverB = new ConcreateObserverB();

            subject.Add(concreateObserverA).Add(concreateObserverB);

            subject.Notify();

            DesignPattern.Observer.SubjectEvent subjectEvent = new DesignPattern.Observer.SubjectEvent();
            subjectEvent.NotifyEvent += concreateObserverA.Notify;
            subjectEvent.NotifyEvent += concreateObserverB.Notify;
            subjectEvent.Notify();
        }
    }
}
