struct testcost
{
    char test[20];
    int bill;
};
struct patient
{
    char pid[10];
    char name[20];
    char age[4];
    char addrs[20];
    char doc[20];
    char department[20];
    struct testcost b;
    char phn[10];
};
struct patient *ptr;
