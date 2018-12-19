#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>//for system calls
#include<fstream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>

#include "student.h"
#include "staff.h"
#include "result.h"
#include "fee.h"
using namespace std;

int main()
{

    int choice;
    for(;;)
    {
            cout <<endl<<endl;
            cout << "\t\t\t\t!...**WELCOME TO SCHOOL MANAGEMENT SYSTEM**...!"<< endl<<endl;
            cout << "1. Student Information"<< endl;
            cout << "2. Staff Information"<< endl;
            cout << "3. Result Information"<< endl;
            cout << "4. Fee Structure"<< endl;
            cout << "5. Exit"<< endl;
            cout << "Enter your choice:"<< endl;
            cin>>choice;
            switch(choice)
            {
                case 1:
                            int studentC;
                            cout <<endl;
                            cout << " **STUDENT** "<< endl;
                            cout << "1. New Registration"<< endl;
                            cout << "2. Update student information"<< endl;
                            cout << "3. Delete student information"<< endl;
                            cout << "4. List All students"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>studentC;
                            switch(studentC)
                            {
                                case 1:
                                    newStudentRegistration();
                                    break;
                                case 2:
                                    updateStudentInform();
                                    break;
                                case 3:
                                    deleteStudentInform();
                                    break;
                                case 4:
                                    listOfStudents();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"wrong option, please retry";
                            }
                    break;
                case 2:
                            int staffC;

                            cout <<endl;
                            cout << " **STAFF** "<< endl;
                            cout << "1. New Registration"<< endl;
                            cout << "2. Update staff information"<< endl;
                            cout << "3. Delete staff information"<< endl;
                            cout << "4. List All staffs"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>staffC;
                            switch(staffC)
                            {
                            case 1:
                                newStaffRegistration();
                                break;
                            case 2:
                                    updateStaffInform();
                                    break;
                            case 3:
                                    deleteStaffInform();
                                    break;
                            case 4:
                                    listOfStaffs();
                                    break;

                            case 5:exit(0);
                            break;
                            default:
                                    cout<<"wrong option, please retry";
                            }
                    break;

                case 3:
                            int resultC;
                            cout <<endl;
                            cout << " **RESULT** "<< endl;
                            cout << "1. Add Result "<< endl;
                            cout << "2. Update Result"<< endl;
                            cout << "3. Delete Result"<< endl;
                            cout << "4. Over All class Result"<< endl;
                            cout << "5. School Annual Result"<< endl;
                            cout << "6. Student Result"<< endl;
                            cout << "7. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>resultC;
                            switch(resultC)
                            {
                            case 1:
                                    newResultAdd();
                                    break;
                            case 2:
                                    updateResultAdd();
                                    break;
                            case 3:
                                    deleteResult();
                                    break;
                            case 4:
                                    overAllClassResult();
                                    break;
                            case 5:
                                    schoolResult();
                                    break;
                            case 6:
                                    studentResult();
                                    break;
                            case 7:exit(0);
                                break;
                                default:
                                        cout<<"wrong option, please retry";
                            }
                    break;
                case 4:
                            int feeC;
                            cout <<endl;
                            cout << " **FEE** "<< endl;
                            cout << "1. Add New Fee"<< endl;
                            cout << "2. Update Fee Information"<< endl;
                            cout << "3. Delete Fee information"<< endl;
                            cout << "4. List All Fees"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>feeC;
                            switch(feeC)
                            {
                                case 1:
                                    addFee();
                                    break;
                                case 2:
                                    updateFee();
                                    break;
                                case 3:
                                    deleteFee();
                                    break;
                                case 4:
                                    listAllFees();
                                    break;
                                case 5:
                                    exit(0);
                                    break;
                                default:
                                    cout<<"wrong option, please retry";
                            }
                            break;
                case 5:exit(0);
                        break;
                default:cout<<"wrong entry, please re-try";
            }
    }



typedef struct student
{
 string rId;//for Registration No number
 string fName;//for student first name
 string lName;//for student last name
 string level;
 string programme;//for class info
 string mNumber;//for Mobile number
};


void newStudentRegistration()
{
    fstream outfile ("studentInfo.txt",ios::app);
    student s1;
    cout<<"Registration Id: ";
    cin>>s1.rId;
    cout<<"FirstName: ";
    cin>>s1.fName;
    cout<<"LastName: ";
    cin>>s1.lName;
    cout<<"Level: ";
    cin>>s1.level;
    cout<<"Programme: ";
    cin>>s1.programme;
    cout<<"Mobile Number: ";
    cin>>s1.mNumber;
    outfile<<s1.rId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.level<<" "<<s1.programme<<" "<<s1.mNumber<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return 0;
}

void updateStudentInform()
{



    string rId;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;

    student s1;
    fstream infile ("studentInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;


    while(std::getline(infile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && rId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"FirstName: ";
            cin>>s1.fName;
            cout<<"LastName: ";
            cin>>s1.lName;
            cout<<"Level: ";
            cin>>s1.level;
            cout<<"Programme: ";
            cin>>s1.programme;
            cout<<"Mobile Number: ";
            cin>>s1.mNumber;
            tempfile<<rId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.level<<" "<<s1.programme<<" "<<s1.mNumber<<endl;
            cout<<"\n**Successfully updated**\n";
        }
        else
        {
            tempfile<<line<<endl;
        }


    }
    infile.close();
    tempfile.close();
    remove("studentInfo.txt");
    rename("tempInfo.txt","studentInfo.txt");

}

void deleteStudentInform()
{
    string rId;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;

    student s1;
    fstream infile ("studentInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && rId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            tempfile<<line<<endl;
        }
        else
        {
            cout<<"\n **Deleted successfully**\n";
        }


    }
    infile.close();
    tempfile.close();
    remove("studentInfo.txt");
    rename("tempInfo.txt","studentInfo.txt");



}


void listOfStudents()
{
    ifstream file("studentInfo.txt");
    string content;
    cout<<endl<<"\t\t\t\t !** STUDENT LIST **!\t\t\n\n\n";
    cout << setw(15) <<"REG.ID:" << setw(15) << "F.NAME" << setw(15) << "L.NAME" << setw(15) << "LEVEL"<<setw(15) << "PROGRAMME"<<setw(15)<<"M.NUMBER"<< endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        std::cout << '\n';

    }


}




typedef struct staff
{
 string id;// for staff id
 string fName;//for student first name
 string lName;//for student last name
 string qualification;//for Registration No number
 string mNumber;//for class info
 string pay;//Pay of the Teacher
};


void newStaffRegistration()
{
    fstream outfile ("staffInfo.txt",ios::app);
    staff s1;
    cout<<"StaffId:";
    cin>>s1.id;
    cout<<"FirstName:";
    cin>>s1.fName;
    cout<<"LastName:";
    cin>>s1.lName;
    cout<<"Pay:";
    cin>>s1.pay;
    cout<<"Qualification:";
    cin>>s1.qualification;
    cout<<"Mobile Number:";
    cin>>s1.mNumber;
    outfile<<s1.id<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.pay<<" "<<s1.qualification<<" "<<s1.mNumber<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}
void updateStaffInform()
{
    string sId;
    cout<<"\n Enter staff Id:\n";
    cin>>sId;

    staff s1;
    fstream infile ("staffInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && sId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"FirstName:";
            cin>>s1.fName;
            cout<<"LastName:";
            cin>>s1.lName;
            cout<<"Pay:";
            cin>>s1.pay;
            cout<<"Qualification:";
            cin>>s1.qualification;
            cout<<"Mobile Number:";
            cin>>s1.mNumber;
            tempfile<<sId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.pay<<" "<<s1.qualification<<" "<<s1.mNumber<<endl;
            cout<<"\n**Successfully updated**\n";

        }
        else
        {

            tempfile<<line<<endl;
        }
    }
    infile.close();
    tempfile.close();
    remove("staffInfo.txt");
    rename("tempInfo.txt","staffInfo.txt");

}
void deleteStaffInform()
{
        string sId;
    cout<<"\n Enter staff Id:\n";
    cin>>sId;

    staff s1;
    fstream infile ("staffInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && sId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            tempfile<<line<<endl;
        }
        else
        {
            cout<<"\n\n ** deleted successfully**\n";

        }
    }
    infile.close();
    tempfile.close();
    remove("staffInfo.txt");
    rename("tempInfo.txt","staffInfo.txt");

}

void listOfStaffs()
{

    fstream file ("staffInfo.txt");
    staff s1;
cout<<endl<<"\t\t\t\t !** STAFF LIST **!\t\t\n\n\n";
    cout<<setw(15)<<"S.ID"<<setw(15)<<"F.NAME:"<<setw(15)<<"L.NAME"<<setw(15)<<"PAY"<<setw(15)<<"QUALIFICATION"<<setw(15)<<"M.NUMBER"<<endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        cout<<endl;
    }
        cout<<endl;

}




typedef struct result
{
 string rId;//for Registration No number
 string programme;//for classNo number
 string ghlanguage;//for kannada
 string english;//for english
 string science;//for science
 string maths;//for maths
 string sStudy;//for sStudy
};



void newResultAdd()
{
    fstream outfile ("resultInfo.txt",ios::app);
    result s1;
    cout<<"Registration Id: ";
    cin>>s1.rId;
    cout<<"Programme: ";
    cin>>s1.programme;
    cout<<"Ghanaian Language: ";
    cin>>s1.ghlanguage;
    cout<<"English: ";
    cin>>s1.english;
    cout<<"Maths: ";
    cin>>s1.maths;
    cout<<"science: ";
    cin>>s1.science;
    cout<<"s.study: ";
    cin>>s1.sStudy;
    outfile<<s1.rId<<" "<<s1.programme<<" "<<s1.ghlanguage<<" "<<s1.english<<" "<<s1.maths<<" "<<s1.science<<" "<<s1.sStudy<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;

}
void updateResultAdd()
{
    string rId,programme;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;
    cout<<"\n Enter student Programme:\n";
    cin>>programme;

    result s1;
    fstream infile ("resultInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && rId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"Ghanaian Language: ";
            cin>>s1.ghlanguage;
            cout<<"English: ";
            cin>>s1.english;
            cout<<"Maths: ";
            cin>>s1.maths;
            cout<<"science: ";
            cin>>s1.science;
            cout<<"s.study: ";
            cin>>s1.sStudy;
            tempfile<<rId<<" "<<programme<<" "<<s1.ghlanguage<<" "<<s1.english<<" "<<s1.maths<<" "<<s1.science<<" "<<s1.sStudy<<endl;
            cout<<"\n**Successfully updated**\n";

        }
        else
        {
            tempfile<<line<<endl;

        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");


}
void deleteResult()
{

        string rId,programme;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;
    cout<<"\n Enter student Programme:\n";
    cin>>programme;

    result s1;
    fstream infile ("resultInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && rId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            tempfile<<line<<endl;
        }
        else
        {
            cout<<"\n\n ** deleted successfully**\n\n";
        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");



}

void overAllClassResult()
{
    string programme;
    cout<<"Enter the Programme:";
    cin>>programme;

    int failCount=0,passCount=0,totalCount=0;

    ifstream file("resultInfo.txt");
    string line;
    int check_fail=0;
    while(std::getline(file, line))
    {
            check_fail=0;
            istringstream ss(line);
            std::istream_iterator<std::string> begin(ss), end;
            //putting all the tokens in the vector
            std::vector<std::string> arrayTokens(begin, end);
            vector<string>::iterator it;
            int flag=0,i=0;
            for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
            {
                string p=*it;
                stringstream geek(p);
                // The object has the value 12345 and stream
                // it to the integer x
                int x = 0;
                geek >> x;
                if(flag==1)
                {
                    if(x<35)
                    {
                        check_fail=1;
                        failCount++;
                        break;
                    }
                    else
                    {
                        continue;
                    }

                }
                if(programme==(*it) && i==1)
                {
                        flag=1;
                        totalCount++;
                }
                i++;

            }
            if(check_fail==0 && flag==1)
            {
                passCount++;
            }

        }
        cout<<endl<<"\t\t\t\t !** PROGRAMME "<<programme<<" RESULT**!\t\t\n\n\n";
        cout<<"Total No. of Failed Students:"<<failCount<<endl;
        cout<<"Total No. of Passed Students:"<<passCount<<endl;
        cout<<"Total No. of Students:"<<totalCount<<endl;
        cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
        cout<<endl;

}

void schoolResult()
{
    int failCount=0,passCount=0,totalCount=0;
    ifstream file("resultInfo.txt");
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int flag=0,i=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            string p=*it;
            stringstream geek(p);
            // The object has the value 12345 and stream
            // it to the integer x
            int x = 0;
            geek >> x;

            if(x<35 && i>1)
            {
                flag=1;
                failCount++;
                break;
            }
            i++;

        }
        if(flag==0)
        {
            passCount++;

        }


        totalCount++;
    }

    cout<<"Total No. of Failed Students:"<<failCount<<endl;
    cout<<"Total No. of Passed Students:"<<passCount<<endl;
    cout<<"Total No. of Students:"<<totalCount<<endl;
    cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
    cout<<endl;
}

void studentResult()
{
    string rId;
    cout<<"\nEnter student Reg.ID:";
    cin>>rId;
    ifstream file("resultInfo.txt");
    string line;
    int s_result=1;
    string r1;
    int total=0;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int flag=0,i=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
             string p=*it;
             stringstream geek(p);
             // The object has the value 12345 and stream
             // it to the integer x
             int x = 0;
            geek >> x;
            if(flag==1)
            {
                total+=x;
                if(x<35)
                {
                    s_result=0;
                    break;
                }
                else
                {
                    continue;
                }

            }
            if(rId==(*it) && i==0)
            {
                flag=1;
                it++;
                r1=line;
            }
            else
                break;

        }
    }
        cout<<endl<<"\t\t\t\t !** STUDENT RESULT **!\t\t\n\n\n";
        cout<<setw(10)<<"Reg.Id";
        cout<<setw(10)<<"Class";
        cout<<setw(10)<<"Ghanaian Language";
        cout<<setw(10)<<"English";
        cout<<setw(10)<<"Maths";
        cout<<setw(10)<<"Science";
        cout<<setw(10)<<"S.study";
        cout<<endl;
        istringstream ss(r1);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            cout<<setw(10)<<*it;
        }

        if(s_result==0)
        {
            cout<<"**Result is Fail**";
        }
        else
        {
            cout<<"\n\n\tTotal Score->"<<total<<endl;
            cout<<"\tTotal Percentage(%)->"<<((double)total/500)*100<<"%"<<endl;
            cout<<"\t**Result is Pass**";
        }
        cout<<endl;
}








typedef struct fee
{
 string classes;//for classNo number
 string year;//for kannada
 float tuitionFee;//for english
 float sportsFee;//for science
 float uniformFee;//for maths
 float total;//for sStudy
};

void addFee()
{
    fee s1;
    fstream outfile ("feeInfo.txt",ios::app);
    cout<<"Class(Standard):";
    cin>>s1.classes;
    cout<<"Year:";
    cin>>s1.year;
    cout<<"SportsFee:";
    cin>>s1.sportsFee;
    cout<<"TuitionFee:";
    cin>>s1.tuitionFee;
    cout<<"UniformFee:";
    cin>>s1.uniformFee;
    s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
    outfile<<s1.classes<<" "<<s1.year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}

void updateFee()
{
    string classes,year;
    cout<<"\n Enter class(STANDARD):\n";
    cin>>classes;

    cout<<"\n Enter Year:\n";
    cin>>year;

    fee s1;
    fstream infile ("feeInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;
    while(std::getline(infile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && classes==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"SportsFee:";
            cin>>s1.sportsFee;
            cout<<"TuitionFee:";
            cin>>s1.tuitionFee;
            cout<<"UniformFee:";
            cin>>s1.uniformFee;
            s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
            tempfile<<classes<<" "<<year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
            cout<<"\n**Successfully updated**\n";

        }
        else
        {
                tempfile<<line<<endl;
        }

    }
    infile.close();
    tempfile.close();
    remove("feeInfo.txt");
    rename("tempInfo.txt","feeInfo.txt");

}

void listAllFees()
{
    ifstream file("feeInfo.txt");
    string content;
    cout<<endl<<"\t\t\t\t !** FEES LIST **!\t\t\n\n\n";
    cout << setw(15) <<"CLASS" << setw(15) << "YEAR" << setw(15) << "S.FEE" <<setw(15) <<"T.FEE"<<setw(15)<<"U.FEE"<<setw(15)<<"TOTAL"<<endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        std::cout << '\n';

    }


}

void deleteFee()
{
    string classes,year;
    cout<<"\n Enter class(STANDARD):\n";
    cin>>classes;

    fee s1;
    fstream infile ("feeInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;
    int p=0;
    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && classes==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            tempfile<<line<<endl;
        }
        else{
            cout<<"** successfully Deleted **\n";
        }


    }

    infile.close();
    tempfile.close();
    remove("feeInfo.txt");
    rename("tempInfo.txt","feeInfo.txt");
}

return 0;
}
