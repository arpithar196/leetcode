class DiningPhilosophers {
public:
    mutex forks[5];
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left=philosopher;
        int right=(philosopher+1)%5;
        if(philosopher==4){
        forks[right].lock();
        forks[left].lock();
        pickLeftFork();  
        pickRightFork();
        }
        else{
        forks[left].lock();
        forks[right].lock();
        pickLeftFork();  
        pickRightFork();
        }
        eat();
        putLeftFork();       
        putRightFork();
        forks[left].unlock();
        forks[right].unlock();
    }
};