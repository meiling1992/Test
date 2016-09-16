#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <algorithm>
#define MIN_TWO(X,Y) X<Y?X:Y
#define MIN_THREE(X,Y,Z) X<Y?X:Y<Z?X:Z
using namespace std;
int main(){
cout<<"hello world"<<endl;
array<int,4> array={10,3,1,2};
vector<int> vec_array;
for(const auto&i:array)
vec_array.push_back(i);
for(const auto&i:vec_array)
cout<<i<<" ";
cout<<endl;
cout<<"sort greater"<<endl;
sort(vec_array.begin(),vec_array.end(),greater<int>());
for(const auto&i:vec_array)
cout<<i<<" ";
cout<<endl;
cout<<"bind2nd//binary_function//unary_function"<<endl;
auto temp_n=count_if(vec_array.begin(),vec_array.end(),bind2nd(greater_equal<int>(),3));
cout<<"greater_equal "<<3<<" counts="<<temp_n<<endl;
cout<<"DP"<<endl;int array_dp[]={1,3,5};
vector<int> vec_dp(11,0);
auto function=[](int num,vector<int> &vec,int array[]){
for(int i=1;i<=num;i++){
if(i==array[0]||i==array[1]||i==array[2])
vec[i]=1;
else if(i>array[3]){
vec[i]=MIN_THREE(vec[i-array[0]],vec[i-array[1]],vec[i-array[2]])+1;
}
else if(i>array[1]){
vec[i]=MIN_TWO(vec[i-array[0]],vec[i-array[1]])+1;
}
else{
vec[i]=vec[i-1]+1;
}
}
return vec[num];
};
auto dp_n=function(11,vec_dp,array_dp);
cout<<dp_n<<endl;
return 0;
}

