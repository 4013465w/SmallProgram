#include<iostream>
#include<string>
using namespace std;
char put[100];
string map[]={"#","begin","if","then","while",
 "do","end","","","",
 "l(l|d)*","dd*","","+","-",
 "*","/",":",":=","",
 "<","<>","<=",">",">=",
 "=",";","(",")"};
 
bool is_letter(char s){
 if(s>='a'&&s<='z'||s>='A'&&s<='Z'){
 return 1;
 }else{
 return 0;
 }
}
bool is_num(char s){
 if(s>='0'&&s<='9'){
 return 1;
 }else{
 return 0;
 }
}
bool is_fh(char s){
 for(int i=13;i<=28;i++){
 if(i==19){
 i++;
 }
 if(s==map[i][0]){
 return 1;
 }
 }
 return 0;
}
void coutstr(int start,int end,string a){
 for(;start<end;start++){
 cout<<a[start];
 }
 
}
int main(){
 string s;
 while(cin>>s&&s[0]!='#'){
 int i=0,n=0,j,bool_s;
 
 while(s[i]!='#'&&i<s.size()){
 if(s[i]==','){
 i++;
 continue;
 }
 if(is_letter(s[i])){
 bool_s=0;
 for(j=1;j<7;j++){
 n=0;
 while(s[i+n]==map[j][n]&&n<=s.size()){
 n++;
 }
 
 if(n-1==s.size()){
 cout<<'('<<j<<','<<map[j]<<')'<<endl;
 i+=n;
 bool_s=1;
 }
 }
 if(!bool_s){
 j=i;
 while(!is_fh(s[i])&&s[i]!=' '&&s[i]!=';'&&s[i]!=','&&i<s.size()){
 i++;
 }
 cout<<'('<<10<<',';
 coutstr(j,i,s);
 cout<<')'<<endl;
 }
 }
 if(is_num(s[i])){
 j=i;
 while(is_num(s[i])){
 i++;
 }
 cout<<'('<<11<<',';
 coutstr(j,i,s);
 cout<<')'<<endl;
 }
 for(j=18;j<=24;j++){
 if(j==19||j==23||j==20){
 j++;
 }
 if(s[i]==map[j][0]&&s[i+1]==map[j][1]){
 cout<<'('<<j<<','<<s[i]<<s[i+1]<<')'<<endl;
 i++; i++;
 }
 }
 if(s[i]=='<'){
 cout<<'('<<20<<','<<s[i]<<')'<<endl;
 i++;
 }
 if(s[i]=='>'){
 cout<<'('<<23<<','<<s[i]<<')'<<endl;
 i++;
 }
 for(j=13;j<=17;j++){
 if(s[i]==map[j][0]){
 cout<<'('<<j<<','<<s[i]<<')'<<endl;
 i++;
 }
 }
 for(j=25;j<=28;j++){
 if(s[i]==map[j][0]){
 cout<<'('<<j<<','<<s[i]<<')'<<endl;
 i++;
 }
 }
 
 }
 }
return 0;
}