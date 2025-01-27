#ifndef FORK_HH
#define FORK_HH

class Fork
{
    int d_pid;

    public:
        virtual ~Fork();
        void fork();
        int pid() const;                    //made public for easy access
    protected:
        int waitForChild();                 // returns the status

    private:
        virtual void childRedirections();
        virtual void parentRedirections();

        virtual void childProcess() = 0;    // pure virtual members
        virtual void parentProcess() = 0;
};

inline int Fork::pid() const
{
    return d_pid;
}

#endif