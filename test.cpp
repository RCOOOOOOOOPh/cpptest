#include <iostream>
//#include <cctype>
#include <vector>
using namespace std;

vector<int> drawLine(int length, int w, int x1, int x2, int y) 
{
    vector<int> answer(length);
    int width = w / 32;
    for(int i = 0; i < width; i++)
    {
        int mynum = 0;
        for(int n = 0; n < 32; n++)
        {
            if(i*32+n >= x1 && i*32+n <= x2)
            {
                mynum++;
            }
            if(n != 31)
            {
                mynum <<= 1;
            }
            //cout<<"mynum="<<mynum<<endl;
        }
        //cout<<"finally mynum="<<mynum<<endl;
        answer[y*width+i] = mynum;
    }
    return answer;
}

int myAtoi(string s)
{
    int answer = 0;
    int ptr = 0;
    int positive = 1;
    while(s[ptr] == ' ') ptr++;
    if(s[ptr] == '-' || s[ptr] == '+') 
    {
        if(s[ptr] == '-')positive=-1;
        ptr++;
    }
    while(ptr<s.size())
    {
        if(isdigit(s[ptr]))
        {
            if(positive == 1 && (answer > 214748364 || (answer == 214748364 && s[ptr]-'0'>=7))) return 2147483647;
            if (positive == -1 && (answer > 214748364 || (answer == 214748364 && s[ptr]-'0'>=8))) return -2147483648;
            answer = answer * 10 + int(s[ptr]-'0');
        }
        else
        {
            return answer*positive;
        }
        ptr++;
    }
    return answer*positive; 
}

class Bitset {
private:
    bool* mybitset;
    int mysize;
    int mycount;
public:
    
    Bitset(int size):mycount(0), mysize(size) 
    {
        mybitset = new bool(size);//不能写成bool* mybitset = new bool(size)!!!!这样的话就不是初始化类成员，而是另外建立了一个变量
        for(int i = 0; i < size; i++) mybitset[i] = false;
        //for(int i = 0; i < size; i++) cout<<this->mybitset[i]<<endl;
    }
    
    void fix(int idx) 
    {
        if(mybitset[idx] == false)
        {
            mybitset[idx] = true;
            mycount++;
        }
    }
    
    void unfix(int idx) 
    {
        if(mybitset[idx] == true)
        {
            mybitset[idx] = false;
            mycount--;
        }
    }
    
    void flip() 
    {
        for(int i = 0;i < mysize;i++) mybitset[i] = !mybitset[i];
    }
    
    bool all() 
    {
        return mycount == mysize;
    }
    
    bool one() 
    {
        return mycount;
    }
    
    int count() 
    {
        return mycount;
    }
    
    string toString() 
    {
        string s = "";
        for(int i = 0; i < mysize; i++)
        {
            if(mybitset[i]) s += "1";
            else s += "0";
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
//????????为什么在电脑上可以正常运行，在leetcode上就说我访问越界
//以及C++的访问越界报错谁tm看得懂，有毛病啊。。。哪句语句报的错，倒是显示出来啊

int main()
{
    Bitset* obj = new Bitset(5);
    obj->fix(3);
    obj->fix(1);
    obj->flip();
    cout<<obj->all()<<endl;
    //"Bitset","fix","fix","flip","all","unfix","flip","one","unfix","count","toString"
    obj->unfix(0);
    obj->flip();
    cout<<obj->one()<<endl;
    obj->unfix(0);
    cout<<obj->count()<<endl;
    cout<<obj->toString()<<endl;
    return 0;
}