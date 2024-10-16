#include<iostream>
using namespace std;

struct obj{
    double profit;
    double weight;
    double ratio;
};

void input(obj arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"Enter weight of object:";
        cin>>arr[i].weight;
        cout<<"Enter profit of object:";
        cin>>arr[i].profit;
        arr[i].ratio = (arr[i].profit/arr[i].weight);
    }
}

void sort(obj arr[],int n){
    obj temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].ratio<arr[j+1].ratio){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void output(obj arr[],int n,int w){
    int rw=w;
    double totalProfit = 0;
    sort(arr,n);
    cout<<"weight\tprofit\tratio\n";
    for(int i=0;i<n;i++){
        cout<<arr[i].weight<<"\t"<<arr[i].profit<<"\t"<<arr[i].ratio<<"\n";
    }

    for(int i=0;i<n;i++){
        if(rw>=arr[i].weight){
            totalProfit+=arr[i].profit;
            rw-=arr[i].weight;
        }
        else{
            totalProfit+=arr[i].profit*(rw/arr[i].weight);
            rw = 0;
        }
        if(rw==0) break;
    }
    cout<<"total profit is"<<totalProfit<<endl;
}

int main(){
    int n,w;
    cout<<"Enter number of objects:";
    cin>>n;
    cout<<"Enter total bag weight";
    cin>>w;
    obj arr[n];
    input(arr,n);
    output(arr,n,w);
    return 0;
}