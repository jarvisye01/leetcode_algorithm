package leetcode_1117;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class H2O {
    private int hnum, onum;
    private Lock lock;
    private Condition cond;
    public H2O() {
        hnum = onum = 0;
        lock = new ReentrantLock();
        cond = lock.newCondition();
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        lock.lock();
        while (hnum == 2 * onum + 2)
            cond.await();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        hnum++;
        lock.unlock();
        cond.signalAll();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        lock.lock();
        while (hnum == 2 * (onum - 1) || hnum == 2 * onum - 1)
            cond.wait();
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        releaseOxygen.run();
        onum++;
        lock.unlock();
        cond.signalAll();
    }
}
