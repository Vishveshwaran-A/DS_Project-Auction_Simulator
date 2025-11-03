#include "linked.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "binaryHeap.hpp"
#include <math.h>
#include<iomanip>
using namespace std;

class Admin
{   
    double total;
    double donation;
    double left;

    public:
        
            Admin(int t=0, int d=0, int l=0)
            {
                total=t;
                donation=d;
                left=total-donation;
            }

            friend ostream& operator<<(ostream& out, const Admin& a) {
                if (&out == &cout) {
                
                    out << "\n\n=== Donation Stats ===\n";
                    out <<std::left<<setw(27)<<"Total Amount Collected: " << formatMoney(a.total) << "\n";
                    out <<std::left<<setw(27)<< "Total Amount Donated: " << formatMoney(a.donation) << "\n";
                    out <<std::left<<setw(27)<< "Remaining Amount: " << formatMoney(a.left) << "\n";
                    out << "===================\n";
                } else {
                
                    out << a.total << " " << a.donation << " " << a.left << "\n";
                }
                return out;
            }

            
            friend istream& operator>>(istream& in, Admin& a) 
            {
                if (&in == &cin) {
                    cout << "Enter Total, Donations, Left: ";
                    in >> a.total >> a.donation >> a.left;
                } else {
                    
                    in >> a.total >> a.donation >> a.left;
                }
                return in;
            }
           
            void saveAdmin(string filename) {
                ofstream fout(filename);
                if (!fout) {
                    cerr << "Error opening file for saving Admin.\n";
                    return;
                }
                fout << *this;  
                fout.close();
            }

    
            void loadAdmin(string filename) {
                ifstream fin(filename);
                if (!fin) {
                    cerr << "Error opening file for loading Admin.\n";
                    return;
                }
                fin >> *this;  
                fin.close();
            }
        void member_access(LinkedList<Member> &l)
        {

            Member value;
            int choice,index,val;
            cout << "Menu: \n"
            << "1. Insert " 
            << "\n2. Delete by Position  "
            << "\n3. Delete by ID  "
            << "\n4. Display Members  "
            << "\n5. Total number of Members  "
            << "\n6. Search by ID  "
            << "\n7. Reverse the list  "
            << "\n8. Sort by Donation  "
            << "\n-1. Go Back.\n\n";
            
            do{
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) 
                {
                    case 1:
                        cout<<"Enter Position:(-1 to append): ";
                        cin>>index;
                        cin >> value;
                        if(l.search(value.getID())==-1){
                            if(index==-1)
                                l.end_insert(value);
                            if(index==1)
                                l.begin_insert(value);
                            else 
                                l.middle_insert(value,index-1);
                        }
                        else{
                            cout<<"ID Already Exists!\n";
                        }
                        cout << "\n";
                        break;
                    // case 2:
                    //     cout << "Enter index to insert at: ";
                    //     cin >> index;
                    //     cin >> value;
                    //     l.middle_insert(value, index);
                    //     cout << "\n";
                    //     break;
                    // case 3:
                    //     cin >> value;
                    //     l.end_insert(value);
                    //     cout << "\n";
                    //     break;
                    case 2:
                        cout<<"Enter position:  ";
                        cin>>index;
                        if(index==1)
                            l.begin_delete();
                        else 
                            l.middle_delete(index-1);
                        cout << "\n";
                        break;
                    // case 5:
                    //     cout << "Enter index to delete: ";
                    //     cin >> index;
                    //     l.middle_delete(index);
                    //     break;
                    // case 6:
                    //     l.end_delete();
                    //     break;
                    case 3:
                    {
                        cout << "Enter ID to delete: ";
                        cin >> val;
                        int k=l.search(val);
                        if(k==-1) break;
                        if(k==0)  
                           l.begin_delete();
                        else      
                            l.middle_delete(k);
                        cout<<endl;
                        break;
                    }
                        
                    case 4:
                        cout<<endl;
                        l.print();
                        cout << "\n";
                        break;

                    case 5:
                        cout << "Total number of members: " << l.length() << "\n\n";
                        break;

                    case 6:
                        cout << "Enter value to search: ";
                        cin >> val;
                        cout<<l.getValue(l.search(val))<<endl<<endl;
                        break;
                    case 7:
                        l.reverse();
                        cout << "List reversed.\n\n";
                        break;
                    case 8:
                        l.sort();
                        cout << "List sorted.\n\n";
                        break;
                    case -1:
                            cout << "Going Back...\n\n";
                            break;
                    default:
                            cout << "Invalid choice. Please try again.\n\n";
                        
                        
                }
            } while (choice != -1);
        }
        void property_access(Queue<Property> &q)
        {
            Property val;
            int ch;
            cout << "1.Add Property\n"<<"2.Delete Property"<<"\n3.Display"<<"\n-1.Go Back\n";
            do{
                cout << "\nEnter your choice: ";
                cin >> ch;
                switch (ch) 
                {
                    case 1:
                        cin >> val;
                        q.enqueue(val);
                        break;
                    case 2:
                        q.dequeue();
                        break;
                    case 3:
                        q.display();
                        break;
                    case -1:
                            cout << "Going Back...\n\n";
                            break;
                    default:
                            cout << "Invalid choice. Please try again.\n\n";
                }
            } while (ch != -1);
            
        }

        void institue_access(BinaryHeap<Institute> &b)
        {
            int choice;
            
                cout << "\n=== Menu ===\n";
                cout << "1.Insert\n";
                cout << "2.Update\n";
                cout << "3.Delete\n";
                cout << "4.Display\n";
                cout << "-1. Go Back\n";

                do {
                    cout << "\nEnter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            Institute x;
                            cin >> x;
                            b.insert(x);
                            break;
                        }
                        // case 2: {
                        //     Institute x = b.deleteMin();
                        //     cout << "Minimum element " << x << " is deleted\n";
                        //     break;
                        // }
                        case 2: {
                            int idx;
                            double val;
                            cout << "Enter S.No and value to Increase or Decrease: ";
                            cin >> idx >> val;
                            if(val<0)
                                b.decreaseKey(idx, -val);
                            else 
                                b.increaseKey(idx,val);
                            break;
                        }
                        // case 4: {
                        //     int idx, val;
                        //     cout << "Enter index and value to increase: ";
                        //     cin >> idx >> val;
                        //     b.increaseKey(idx, val);
                        //     break;
                        // }
                        case 3: {
                            int idx;
                            cout << "Enter S.No: ";
                            cin >> idx;
                            b.Delete(idx);
                            break;
                        }
                        case 4:
                            b.display();
                            break;
                        case -1:
                            cout << "Going Back...\n\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n\n";
                    }
            } while (choice != -1);
        }
        void displayStats() 
        {
            cout << "\n=== Donation Stats ===" << endl;
            cout << "Total Amount Collected: " << total << endl;
            cout << "Total Donations Received: " << donation << endl;
            cout << "Remaining Amount / Left: " << left << endl;
            cout << "===================" << endl;
        }
        long nextBid(int current) 
        {
            double increment = current * 0.1;  
            int power = pow(10, floor(log10(increment))); 
            int roundedIncrement = static_cast<int>(ceil(increment / power) * power);
            return current + roundedIncrement;
        }
        void auction(LinkedList<Member> &l,Queue<Property> &q,Queue<Property> &p,BinaryHeap<Institute> &b)
        {   
            int sta;
            cout<<"Enter 1 to Start Auction:";
            cin>>sta;
            cout<<endl;
            if(sta!=1) return;
            Stack<Bid> s;
            line_printer();
            l.print();
            line_printer();
            cout<<endl;
            Property t=q.peek();
            int count=0;
            int ch;
            int x;
            int temp=-1;
            int y=t.getStart();
            cout<<t;
            cout<<"\nStarting Bid: "<<formatMoney(t.getStart())<<endl;
            do
            {   
                cout<<"\nEnter ID of Bidder: ";
                cin>>x; 
                if(x==-1)  continue;
                if(l.search(x)==-1 || l.search(x)==l.search(temp) )
                {   
                    cout<<"Invalid ID\n";
                    continue;
                }
                cout<<"Current Bid: "<<formatMoney(y)<<endl;
                Bid b(x,y);
                s.push(b);
                count++;
                y=nextBid(y);
                temp=x;
                
            }while(x!=-1);
            if(count==0) {

                q.dequeue();
                p.enqueue(t);
                cout<<"Unsold\n";
                return;
            }
            auto winnerId = s.peek().getId();
            auto winningBid = s.peek().getAmount();
            cout << "Property sold to Member ID: "
                << winnerId << " for amount: " << formatMoney(winningBid) << "\n";

            int ind=l.search(s.peek().getId());
            auto p1=l.head;
            for(int i=0;i<ind;i++)
                p1=p1->next;
            
            p1->value.update_donation(s.peek().getAmount());
            q.dequeue();
            t.update_owner(s.peek().getId());
            t.update_price(s.peek().getAmount());
            p.enqueue(t);
            total += s.peek().getAmount();
            left=total-donation;



        }
        void donate(BinaryHeap<Institute> &b)
        {      
               int count=0;
               while(!b.isEmpty())
                {   
                    count++;
                    cout << "\nCurrent Min Aid: " << formatMoney(b.getMin().getAid()) << "  (Left: " << formatMoney(left) <<")"<< endl;
                    if(left >= b.getMin().getAid())
                    {
                        int aid = b.getMin().getAid();
                        donation += aid;
                        left = total - donation;
                        cout << "Amount "<<formatMoney(aid)<<" Donated to "<<b.getMin().getName()<< endl;
                        b.deleteMin();
                    }
                    else
                    {
                        cout<<"Not Enough Fund.\n"; 
                        break;  
                    }

                }
                
                if(count==0)  
                {    
                    cout<<"No Institutes.\n";
                }
        }
   
    
};

int main()
{    
     Admin a;
     LinkedList<Member> l;
     l.loadLinkedList("./member.dat");
     Queue<Property> q,p;
     q.loadQueue("./property.dat");
     p.loadQueue("./property1.dat");
     BinaryHeap<Institute> i;
     i.loadHeap("./Institutes.dat");
     a.loadAdmin("./admin.dat");




     int choice;
     do 
     {
        cout << "\nMenu: (Enter -1 to exit)\n";
        cout << "1.Access Members\n";
        cout << "2.Access Properties\n";
        cout << "3.Sold Properties\n";
        cout << "4.Institues\n";
        cout << "5.Auction\n";
        cout << "6.Donation Statistics\n";
        cout << "7.Donate\n";
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                a.member_access(l);
                break;

            case 2:
                a.property_access(q);
                break;
            case 3:
                a.property_access(p);
                break;
            
            case 4:
                 a.institue_access(i);
                 break;
                
            case 5:
                a.auction(l,q,p,i);
                break;
            
            case 6:
                cout<<a;
                break;
            case 7:
                a.donate(i);
                break;
            case -1:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, enter again." << endl;
                break;
        }
    }while (choice != -1);
     
    

    l.saveLinkedList("./member.dat");
    q.saveQueue("./property.dat");
    p.saveQueue("./property1.dat");
    i.saveHeap("./Institutes.dat");
    a.saveAdmin("./admin.dat");

}
