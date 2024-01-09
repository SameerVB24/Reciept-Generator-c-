#include<bits/stdc++.h>
using namespace std;

class item{
    public:
    string name;
    int Quantity;
    float rate;
    float totalprice;

    void itemDetail(){
        cout<<"Enter item name: ";
        cin.ignore();// Clear the input buffer
        getline(cin,name);
        cout<<"Enter Quantity: ";
        cin>>Quantity;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores up to a newline
        cout<<"Enter Total Price: ";
        cin>>rate;
    }

    void DisplayDetail(){
        totalprice = Quantity*rate;
        cout<<"   "<<name<<"   \t"<<Quantity<<".00\t"<<rate<<".00\t"<<totalprice<<".00"<<endl;
    }
};

class Hotel{
    public:
    item *arr;
    int n;
    float total;
    int TotalQty=0;

    Hotel(int totalitem){
        this->n = totalitem;
        arr = new item[n];
    }

    void Billinput(){
        for(int i=0;i<n;i++){
            arr[i].itemDetail();
        }
    }
    void DateTime(){
        time_t tmNow = time(0);
        char *dt = ctime(&tmNow);
        cout<<"   Date/Time: "<<dt;
    }

    void HotelData(){
        int a = rand()%200;
        cout<<"             SamWell RESTAURANT         "<<endl;
        cout<<"        1st Floor, Astha Square Near,   "<<endl;
        cout<<"           Uttran Kapodora Bridge       "<<endl;
        cout<<"            Akurdi, PUNE 411035         "<<endl;
        cout<<"         GSTIN NO - 234032895234        "<<endl;
        cout<<"           Invoince Cum Challan         "<<endl;
        cout<<"   -------------------------------------"<<endl;
        this->DateTime();
        cout<<"                Table# "<<a<<"          "<<endl;
        cout<<"   -------------------------------------"<<endl;
        cout<<"   Product\t Qty\t Rate\t Amount\t"<<endl;
        cout<<"   -------------------------------------"<<endl;
    }

    void BillOutput(){
        for(int i=0;i<n;i++){
            arr[i].DisplayDetail();
            total += arr[i].totalprice;
            TotalQty += arr[i].Quantity;
        }
    }

    void theTotal(){
        cout<<"   -------------------------------------"<<endl;
        cout<<"   Sub Total    \t \t  "<<total<<endl;
        double CGST = total*0.09;
        double UGST = total*0.09;
        cout<<"   Output CGST @9% \t \t  "<<double(CGST)<<endl;
        cout<<"   Output CGST @9% \t \t  "<<double(UGST)<<endl;
        cout<<"   -------------------------------------"<<endl;
        cout<<"   Total\tQty:"<<TotalQty<<"\t   Amt:"<<total+UGST+CGST<<endl;

        cout<<"       Thank You For Your Kind Visit       "<<endl;
        
    }

};


int main(){
    Hotel Person1(5);
    Person1.Billinput();
    Person1.HotelData();
    Person1.BillOutput();
    Person1.theTotal();
    return 0;  

}