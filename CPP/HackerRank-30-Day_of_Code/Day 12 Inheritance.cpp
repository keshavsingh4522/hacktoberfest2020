#include <iostream>
#include <vector>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
class Person
{
    protected:
             string firstName, lastName;
             int id;
    public:
            Person(string firstName, string lastName, int identification)
            {
                this ->firstName = firstName;
                this ->lastName = lastName;
                this ->id = identification;
            } 
            void printPerson()
            {
                cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
            }        
};

class Student: public Person
{
    private:
           vector<int> testScores;
    public:
          Student(string firstName, string lastName, int identification, vector<int> scores) : Person(firstName, lastName, identification)
          {
              this ->testScores = scores;
          } 
          char calculate()
          {
              int average = 0;

              for (int i = 0; i < testScores.size(); i++)
              {
                  average += testScores[i];
              }
              average = average/testScores.size();

              if (average >= 90)
              {
                  return '0';
              }
              else if (average >= 80)
              {
                  return 'E';
              }
              else if (average >= 70)
              {
                  return 'A';
              }
              else if (average >= 55)
              {
                  return 'P';
              }
              else if (average >= 40)
              {
                  return 'D';
              }
              else
              {
                  return 'T';
              }
              
          }      
};

int main()
{
    string firstName, lastName;
    int id, numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;

    for (int i = 0; i < numScores; i++)
    {
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student* s = new Student(firstName, lastName, id, scores);
    s ->printPerson();
    cout << "Grade: " << s ->calculate() << "\n";
    return 0;
}