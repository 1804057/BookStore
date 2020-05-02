#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class sell
{
public:
    float price;
    string book;
    string author;
    void get_book()
    {
        cout<<"Book name : ";
        getline(cin,book);
        cout<<"Author name : ";
        getline(cin,author);
        cout<<"Price : ";
        cin>>price;
    }
    string get_b()
    {
        return book;
    }
    void say_data()
    {
        cout<<book<<"\t\t"<<author<<"\t\t"<<price<<"\n";
    }
};
bool sortByName(sell &A, sell &B) //function to sort fruits by names
{
    return (A.author < B.author);
}
bool sortByPrice(sell &A, sell &B)
{
    return (A.price < B.price);
}
bool same(sell &A,string B)
{
    if(A.book==B)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    fstream fio;
    fio.open("sellbook.data",ios::in|ios::out|ios::app);
    vector<sell>seller;
    sell x;
    system("cls");
    cout<<"Welcome....."<<endl;
    cout<<"If you want to buy books, press 'b'. \nIf you want to sell books press 's'.\n";
    char ans;
    char a;
    cin>>a;
    system("cls");
    if(a=='s')
    {
        getchar();
        x.get_book();
        fio.write((char*)&x,sizeof(x));
        cout<<"Want to add more? 'y/n'?"<<endl;
        cin>>a;
        while(a=='y')
        {
            system("cls");
            getchar();
            x.get_book();
            fio.write((char*)&x,sizeof(x));
            cout<<"Want to add more? 'y/n'?"<<endl;
            cin>>a;
        }
    }
    if(a=='n' || a=='b')
    {
        system("cls");
        cout<<"Want to see our book list?'y/n'"<<endl;
        cin>>a;
        if(a=='y')
        {
            system("cls");
            long pos;
            fio.seekg(0);
            while(!fio.eof())
            {
                pos=fio.tellg();
                fio.read((char*)&x,sizeof(x));
                seller.push_back(x);
            }
            seller.pop_back();
            cout<<"Want to sort by author/price?\nIf author, press 'a' if price, press 'p'\n";
            cin>>a;
            if(a=='a')
            {
                system("cls");
                sort(seller.begin(),seller.end(),sortByName);
                cout<<"Book Name\tAuthor Name\tPrice\n";
                sell k;
                for(int i=0;i<seller.size();i++)
                {
                    k=seller[i];
                    k.say_data();
                }
            }
            else if(a=='p')
            {
                system("cls");
                sort(seller.begin(),seller.end(),sortByPrice);
                cout<<"Book Name\tAuthor Name\tPrice\n";
                sell p;
                for(int i=0;i<seller.size();i++)
                {
                    p=seller[i];
                    p.say_data();
                }
            }
            cout<<"Want to buy a book?'y/n'";
            char g;
            cin>>g;
            string b;
            vector<sell>temp;
            if(g=='y')
            {
                getchar();
                getline(cin,b);
                for(int i=0;i<seller.size();i++)
                {
                    if(same(seller[i],b))
                    {
                        cout<<"Book Name\tAuthor Name\tPrice\n";
                        seller[i].say_data();
                    }
                    else
                    {
                        temp.push_back(seller[i]);
                    }
                }
                fio.close();
                fio.open("sellbook.data",ios::in|ios::out|ios::trunc);
                for(int i=0;i<temp.size();i++)
                {
                    x=temp[i];
                    fio.write((char*)&x,sizeof(x));
                }
            }

        }
        else
        {
            return 0;
        }
    }

}

