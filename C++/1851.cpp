#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v, sorted;
bool visited[1000004];
map<int, int> dic;

int main(){
    int n, x, mm, tmp, idx;
    long long ans=0, sum;
    
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        
        v.push_back(x);
        sorted.push_back(x);
    }
    
    sort(sorted.begin(), sorted.end());
    
    for(int i=0; i<n; i++)
        dic[sorted[i]]=i;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(dic[v[i]]==i){
                visited[i]=true;
                
                continue;
            }
            
            mm=v[i], tmp=0, sum=0, idx=i;

            while(!visited[idx]){
                sum+=v[idx];
                tmp++;
                
                if(v[idx]<mm) 
                    mm=v[idx];
                    
                visited[idx]=true;
                
                idx=dic[v[idx]];
            }
            
            sum-=mm;
            ans+=sum+mm*(tmp-1);
            
            if(2*(sorted[0]+mm)<(mm-sorted[0])*(tmp-1))
                ans-=(mm-sorted[0])*(tmp-1)-2*(sorted[0]+mm);
        }
    }
    
    printf("%lld", ans);
    
    return 0;
}
