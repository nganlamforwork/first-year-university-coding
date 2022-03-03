#include <iostream>
#include <vector>

using namespace std;

int d, x, y, a, b;
struct Data{
  int one,two,three,four;  
};

vector<Data> save;
int main() {
    cout<<"Input: ";
    cin>>a>>b;
    a=abs(a); b=abs(b);
    long long BCNN = (long long) a*b;
    while (b!=0 && a!=0){
        if (a<b) swap(a,b);
        cout<<a<<" = "<<a/b<<"."<<b<<" + "<<a%b<<'\n';
        save.push_back({a,a/b,b,a%b});
        int tmp=a;
        a=b;
        b=tmp%b;
    }
    
    cout<<"\nUCLN = "<<a<<'\n';
    cout<<"BCNN = "<<BCNN/(long long)a<<'\n';
    
    Data tmp=save[save.size()-2];
    
    cout<<a<<" = \t";
    cout<<tmp.one<<" + "<<-tmp.two<<'.'<<tmp.three<<'\n';
    
    int cur11=1 ,         cur12=tmp.one;
    int cur21=-tmp.two ,   cur22=tmp.three;
    
    for (int i=save.size()-3;i>=0;i--){
        Data tmp=save[i];
        
        int tmp_cur11=cur21;
        int tmp_cur12=save[i].one;
        
        int tmp_cur21=cur11+cur21*(-save[i].two);
        int tmp_cur22=save[i].three;
        
        
        cout<<a<<" = \t";
        cout<<tmp_cur11<<'.'<<tmp_cur12<<" + "<<tmp_cur21<<'.'<<tmp_cur22<<'\n';
        
        
        cur11=tmp_cur11; cur12=tmp_cur12;
        cur21=tmp_cur21; cur22=tmp_cur22;
    }
    return 0;
}