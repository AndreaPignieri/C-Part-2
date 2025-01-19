#include "task.ih"

void Task::operator()()
{
    ifstream file;   
    file.open(d_fileName);  //opens file as ifstream
    
    if (!file.is_open())   //check if file openend
        throw string("No file");
    
    char c;    //c used as character index
    while (file.get(c))    //loop through file
    {
        if (charSelect(c)) //check if c matches character type
        {
            //ensure access protected and iterate up
            std::lock_guard<std::mutex> lg(d_mutex);
            ++d_count;
        }
    }
}
