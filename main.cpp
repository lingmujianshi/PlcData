#include <iostream>
#include <string>

class Word
{
private:
    int data=1;
    int decimalPlace=3;
public:
    Word() {}
    Word(int i) {data = i;}
    ~Word() {}

    std::string getStr()
    {
        std::string str;
        str = std::to_string(data);
        int lack = decimalPlace - str.size() + 1;
        if (lack > 0)
        {
            for (int i = 0; i < lack; i++)
            {
                str.insert(str.begin(),'0');
            }
        }
        str.insert(str.end()-decimalPlace,'.');
        return str;  
    }

    void putStr(std::string str)
    {
        
        str.erase(std::find(str.begin(),str.end(),'.'));
        data = std::atoi(str.c_str());
    }
};

int main()
{
    Word p(23111);
    std::cout << p.getStr() << std::endl;
    p.putStr("1.234");
    std::cout << p.getStr() << std::endl;
    p.putStr("1.230");
    std::cout << p.getStr() << std::endl;
    return 0;
}
