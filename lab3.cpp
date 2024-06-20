// Implement C++ program for Random password generation
#include <iostream>
using namespace std;
class R_password
{
    public:
    void generate()
    {
        cout << "All possible passwords out of '1, 3, a, s, t and i' are : " << endl;
        string str = "13asti", str1 = "13asti";
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    for (int l = 0; l < 6; l++)
                    {
                        for (int m = 0; m < 6; m++)
                        {
                            for (int n = 0; n < 6; n++)
                            {
                                str1[0] = str[i];
                                str1[1] = str[j];
                                str1[2] = str[k];
                                str1[3] = str[l];
                                str1[4] = str[m];
                                str1[5] = str[n];
                                bool check = true;
                                for (int p = 0; p < 6; p++)
                                {
                                    for (int q = 0; q < 6; q++)
                                    {
                                        if (p == q)
                                            continue;
                                        if (str1[p] == str1[q])
                                            check = false;
                                    }
                                }
                                if (check == true)
                                {
                                    cout << str1 << " ";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};
int main()
{
    R_password obj;
    obj.generate();
    return 0;
}