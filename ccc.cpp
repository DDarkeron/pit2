#include <iostream>
#include <fstream>
//#include <cstdlib>
#include <list>
#include <ctime>
#include <random>
using std::ofstream;
using std::ifstream;
using std::string;
using std::ios;
using std::list;
using std::endl;
using std::cout;
using std::cin;
using std::endl;

//#define PAGECHARS 1000

char *inttostr(int number, char *destination, int base)
{
    int countt = 0;
    do
    {
        int digit = number % base;
        destination[countt++] = (char) ((digit > 9) ? digit - 10 + 'A' : digit + '0');
    }
    while ((number /= base) != 0);
    destination[countt] = '\0';
    int i;
    for (i = 0; i < countt / 2; ++i)
    {
        char symbol = destination[i];
        destination[i] = destination[countt - i - 1];
        destination[countt - i - 1] = symbol;
    }
    return destination;
}

int createid(string base)
{
    int tmp=0;
    for (int i=0; i<base.size(); ++i)
    {
        tmp+=base.c_str()[i];
    }
    return tmp;
}

class PartNode
{
public:
    PartNode();
    ~PartNode();
    PartNode *getnext();
    PartNode *getprev();
    void setnext(PartNode *Newnext);
    void setprev(PartNode *Newprev);
    string getname();
    string getstring();
    void setname(string newname);
    int getid();
    void setid(int newid);
    int getpoints();
    void setpoints(int newp);
private:
    PartNode *next;
    PartNode *prev;
    string name;
    int id;
    int points;
   // int idlen;
};

class PartList
{
public:
    PartList();
    ~PartList();
    void pushfront(string &Newname);
  //  string formstringNth(int i);
    int deleteNth(int i);
   // int deletePtr(PartNode *temp);
    PartNode *getNth(int i);
    PartNode *gethead();
   // PartNode *gettail();
    int getlength();
    int checkstrforex(string &strcheck);
    int writetofile(ofstream &f);
   // int writetofileformat(ofstream &f);
    int readfromfile(ifstream &f);
    void startpart(int pmax);
    void sortname();
    void sortpoints();
    void showres();
    int getmaxw() {return maxw;}
    int getprize() {return prize;}
    void setmaxw(int n) {maxw=n;}
    void setprizes(int n) {prize=n;}
private:
    PartNode *head;
    PartNode *tail;
    int length;
    int maxw;
    int prize;
};

void PartList::sortname()
{
    PartNode *start=head;
    PartNode *tmp;
    PartNode *a;

    int tmppoints;
    int tmpid;
    string tmpname;

    bool flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->getnext();
        flag=0;
        while(a)
        {
            if((tmp->getname())>(a->getname()))
            {
                tmppoints=tmp->getpoints();
                tmpid=tmp->getid();
                tmpname=tmp->getname();

                tmp->setpoints(a->getpoints());
                tmp->setid(a->getid());
                tmp->setname(a->getname());

                a->setpoints(tmppoints);
                a->setid(tmpid);
                a->setname(tmpname);
                flag=1;
            }
            tmp=tmp->getnext();
            a=a->getnext();
        }
    }
}

void PartList::sortpoints()
{
    PartNode *start=head;
    PartNode *tmp;
    PartNode *a;

    if (!head) return;

    if (start->getid()==-1)
    {
        this->sortname();
        return;
    }

    int tmppoints;
    int tmpid;
    string tmpname;

    bool flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->getnext();
        flag=0;
        while(a)
        {
            if((tmp->getpoints())<(a->getpoints()))
            {
                tmppoints=tmp->getpoints();
                tmpid=tmp->getid();
                tmpname=tmp->getname();

                tmp->setpoints(a->getpoints());
                tmp->setid(a->getid());
                tmp->setname(a->getname());

                a->setpoints(tmppoints);
                a->setid(tmpid);
                a->setname(tmpname);
                flag=1;
            }
            tmp=tmp->getnext();
            a=a->getnext();
        }
    }
}

PartNode::PartNode(): next(0),prev(0),points(-1),id(-1),name("") {}

PartNode::~PartNode() {}

PartNode* PartNode::getnext()
{
    return next;
}

PartNode* PartNode::getprev()
{
    return prev;
}

void PartNode::setnext(PartNode *Newnext)
{
    next=Newnext;
}

void PartNode::setprev(PartNode *Newprev)
{
    prev=Newprev;
}

string PartNode::getname()
{
    return name;
}

string PartNode::getstring()
{
    char tmp[34];
    string temp("");
    if (points!=-1)
    {
        temp+="Points: " + string(inttostr(points,tmp,10));
        for (int i=temp.size()-8; i<3; ++i)
            temp+=" ";
    }
    temp+=name;
    temp+=" ID: " + string(inttostr(id,tmp,10));
    return temp;
}

void PartNode::setname(string newname)
{
    name=newname;
}

int PartNode::getid()
{
    return id;
}

void PartNode::setid(int newid)
{
    id=newid;
}

int PartNode::getpoints()
{
    return points;
}

void PartNode::setpoints(int newp)
{
    points=newp;
}

PartList::PartList(): head(0),tail(0),length(0),maxw(0),prize(0) {}
PartList::~PartList()
{
    while (head)
    {
        tail=head->getnext();
        delete head;
        head=tail;
    }
}

int PartList::getlength()
{
    return length;
}

void PartList::pushfront(string &Newname)
{
    PartNode *temp=new PartNode();
    temp->setprev(tail);
    temp->setnext(0);
    temp->setname(Newname);
    temp->setid(createid(Newname));
    if (tail)
        tail->setnext(temp);
    tail=temp;

    if (!head)
        head=temp;
    ++length;
}

int PartList::checkstrforex(string &strcheck)
{
    for (PartNode *ptr=head; ptr; ptr=ptr->getnext())
    {
        if (strcheck==ptr->getname())
        {
            return 1;
        }
    }
    return 0;
}

PartNode* PartList::getNth(int i)
{
    if (i>=length) return 0;
    PartNode *ptr=head;
    for (int j=0; j<i; ++j)
        ptr=ptr->getnext();
    return ptr;
}

int PartList::deleteNth(int i)
{
    if (i>=length) return 0;
    PartNode *temp=getNth(i);
    if (temp->getprev())
        (temp->getprev())->setnext(temp->getnext());
    if (temp->getnext())
        (temp->getnext())->setprev(temp->getprev());
    if (!temp->getprev())
        head=temp->getnext();
    if (!temp->getnext())
        tail=temp->getprev();
    delete temp;
    --length;
    return 1;
}

/*int PartList::deletePtr(PartNode *temp)
{
    if (!temp) return 0;
    if (temp->getprev())
        (temp->getprev())->setnext(temp->getnext());
    if (temp->getnext())
        (temp->getnext())->setprev(temp->getprev());
    if (!temp->getprev())
        head=temp->getnext();
    if (!temp->getnext())
        tail=temp->getprev();
    delete temp;
    --length;
    return 1;
}*/

/*string PartList::formstringNth(int i)
{
    PartNode *ptr=getNth(i);
    return ptr->getstring();
}*/

int PartList::writetofile(ofstream &f)
{
    string str;
    int temp;
    temp=prize;
    f.write(reinterpret_cast<char*>(&temp),sizeof(int));
    temp=maxw;
    f.write(reinterpret_cast<char*>(&temp),sizeof(int));
    for (PartNode *ptr=head; ptr; ptr=ptr->getnext())
    {
        str=ptr->getname();
        temp=str.size();
        f.write(reinterpret_cast<char*>(&temp),sizeof(int));
        f.write(&str[0],str.size()*sizeof(char));
        temp=ptr->getid();
        f.write(reinterpret_cast<char*>(&temp),sizeof(int));
        temp=ptr->getpoints();
        f.write(reinterpret_cast<char*>(&temp),sizeof(int));
    }
    return 1;
}

/*int PartList::writetofileformat(ofstream &f)
{
    list<int>::iterator it;
    list<int>::iterator itend;
    for (PartNode *ptr=head; ptr; ptr=ptr->getnext())
    {
        f<<ptr->getstring()<<endl;
    }
    return 1;
}*/

int PartList::readfromfile(ifstream &f)
{
    string str;
    int temp=0;//temp2=0;

    while (length)
        this->deleteNth(0);

    f.read(reinterpret_cast<char*>(&prize),sizeof(int));
    f.read(reinterpret_cast<char*>(&maxw),sizeof(int));
    while(1)
    {
        f.read(reinterpret_cast<char*>(&temp),sizeof(int));
        if (f.eof()) break;
        str.resize((unsigned int) temp);
        f.read(&str[0],temp*sizeof(char));
        this->pushfront(str);
        f.read(reinterpret_cast<char*>(&temp),sizeof(int));
        tail->setid(temp);
        f.read(reinterpret_cast<char*>(&temp),sizeof(int));
        tail->setpoints(temp);
    }
    return 1;
}

PartNode* PartList::gethead()
{
    return head;
}

/*PartNode* PartList::gettail()
{
    return tail;
}*/

void PartList::startpart(int pmax)
{
    if (!head) return;
    int points=0;
    system("CLS");
    for (PartNode *ptr=head; ptr; ptr=ptr->getnext())
    {
        cout<<"Set points for: "<<ptr->getstring()<<endl;
        cin>>points;
        while ((points<0)||(points>pmax))
        {
            cout<<"Wrong number!"<<endl;
            cin>>points;
        }
        system("CLS");
        ptr->setpoints(points);
    }
}

void PartList::showres()
{
    system("CLS");
    PartNode *ptr=head;
    int i;
    cout<<"Prize winners:"<<endl;
    for (i=0;(i<prize)&&(ptr!=0);ptr=ptr->getnext(),++i)
    {
        cout<<ptr->getstring()<<endl;
    }
    cout<<"Non-prize winners:"<<endl;
    for (;(i<maxw)&&(ptr!=0);ptr=ptr->getnext(),++i)
    {
        cout<<ptr->getstring()<<endl;
    }
    system("Pause");
    system("CLS");
}

int main()
{
    PartList *Plist=new PartList();
  //  PartNode *tempnode=0;
    ofstream fout;
    ifstream fin;
    int i;
    string tmp,command("xxxxxxxxx");
    srand((unsigned int) time(0));
    fin.open("temporal.pt");
    if (fin.is_open())
    {
        Plist->readfromfile(fin);
        fin.close();
    }
    while (true)
    {
        command="xxxxxxx";
        i=1;

        for (PartNode *ptr=Plist->gethead(); ptr; ptr=ptr->getnext())
        {
            cout<<i<<".) "<<ptr->getstring()<<endl;
            ++i;
        }
        cout<<"Maximal participant: "<<Plist->getmaxw()<<"\nPrize places: "<<Plist->getprize()<<endl;
        cout<<"set participant <number> - to set number of participants\n"
                "set prizes <number>  - to set prize places\n"
                "add <name>           - to add new participant\n"
                "delete <number>      - to delete participant\n"
                "start                - to start competition and count points\n"
                "clear                - to remove all points\n"
                "save <filename>      - to save participants\n"
                "load <filename>      - to load participants\n"
                "sortname             - to sort by name\n"
                "sortpoints           - to sort by points\n"
                "exit                 - to exit program"<<endl;
        cin>>command;
        system("CLS");
        if (command=="add")
        {
            cin.get();
            getline(cin,command);
            if (!Plist->checkstrforex(command)&&(Plist->getlength()<Plist->getmaxw()))
            {
                Plist->pushfront(command);
                for (PartNode *ptr=Plist->gethead(); ptr; ptr=ptr->getnext())
                {
                    ptr->setpoints(-1);
                }
            }
        }
        else if (command=="set")
        {
            cin>>command;
            if (command=="participant")
            {
                delete Plist;
                Plist=new PartList();
                cin>>i;
                if (i>0)
                    Plist->setmaxw(i);
                else
                    cout<<"Wrong number"<<endl;
            }
            else if (command=="prizes")
            {
                cin>>i;
                if ((i>0)&&(i<=Plist->getmaxw()))
                    Plist->setprizes(i);
                else
                    cout<<"Wrong number"<<endl;
            }
            else
                cout<<"Unknown value"<<endl;
        }
        else if (command=="exit")
        {
            return 0;
        }
        else if (command=="delete")
        {
            cin>>command;
            Plist->deleteNth(atoi(command.c_str())-1);
        }
        else if (command=="start")
        {
            Plist->startpart(100);
            Plist->sortpoints();
            fout.open("lastwon.txt");
            if (fout.is_open())
            {
                i=1;
                for (PartNode *ptr=Plist->gethead(); ptr; ptr=ptr->getnext())
                {
                    fout<<i<<".) "<<ptr->getstring()<<endl;
                    ++i;
                }
                fout.close();
            }
            Plist->showres();
        }
        else if (command=="results")
        {
            Plist->showres();
        }
        else if (command=="sortpoints")
        {
            Plist->sortpoints();
        }
        else if (command=="sortname")
        {
            Plist->sortname();
        }
        else if (command=="clear")
        {
            for (PartNode *ptr=Plist->gethead(); ptr; ptr=ptr->getnext())
            {
                ptr->setpoints(-1);
            }
        }
        else if (command=="save")
        {
            cin>>command;
            fout.open(command);
            if (fout.is_open())
            {
                Plist->writetofile(fout);
                fout.close();
                continue;
            }
            cout<<"Cant open file"<<endl;
            continue;
        }
        else if (command=="load")
        {
            cin>>command;
            delete Plist;
            Plist=new PartList();
            fin.open(command);
            if (fin.is_open())
            {
                Plist->readfromfile(fin);
                fin.close();
                continue;
            }
            cout<<"Cant open file"<<endl;
            continue;
        }
        else
        {
            cout<<"Unknown command"<<endl;
            continue;
        }

        fout.open("temporal.pt");
        if (fout.is_open())
        {
            Plist->writetofile(fout);
            fout.close();
        }
    }
    }
