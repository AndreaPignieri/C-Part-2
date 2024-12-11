class IWIP  // Abstract interface
{
public:
    virtual void performTask() = 0;  // Pure virtual function
    virtual ~IWIP() = default;
};

class WIP : public IWIP  // Implementation of IWIP
{
public:
    void performTask() override
    {
        // Actual implementation
    }
};

class OpusMagnum
{
    std::unique_ptr<IWIP> d_wip;  // Dependency Injection

public:
    OpusMagnum(std::unique_ptr<IWIP> wip) : d_wip(std::move(wip)) {}

    void execute()
    {
        d_wip->performTask();
    }
};
