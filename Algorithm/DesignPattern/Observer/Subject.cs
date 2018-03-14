using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.DesignPattern.Observer
{
    class Subject
    {
        private List<IObserver> _observers;
        public Subject()
        {
            _observers = new List<IObserver>();
        }
        public Subject Add(IObserver Item)
        {
            _observers.Add(Item);
            return this;
        }
        public Subject Remove(IObserver Item)
        {
            _observers.Remove(Item);
            return this;
        }
        public void Notify()
        {
            EventArgs args = new EventArgs();
            foreach (var observer in _observers)
            {
                observer.Notify(args);
            }
        }
    }

    //Event 방식의 Observer
    class SubjectEvent
    {
        public delegate void NotifyObserver(EventArgs args);
        public event NotifyObserver NotifyEvent;
        public SubjectEvent()
        {
        }
        public void Notify()
        {
            EventArgs args = new EventArgs();
            NotifyEvent(args);
        }
    }
}
