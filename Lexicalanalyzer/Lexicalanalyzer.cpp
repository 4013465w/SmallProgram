#include<iostream>
#include<string>
using namespace std;

string data[100];
int c[100],indexd=0,ans[38][38],indexc=0,j=0;
int i=0;
string demo[38];
bool is_letter(char s){//判断是否为字母
 if(s>='a'&&s<='z'||s>='A'&&s<='Z'){
 return 1;
 }else{
 return 0;
 }
}
bool is_num(char s){//判断手否为数字
 if(s>='0'&&s<='9'){
 return 1;
 }else{
 return 0;
 }
}
bool is_bit2(){//是否为二进制数
  bool result=0;int m=0;
	  if(data[indexd][j]=='+'||data[indexd][j]=='-'){
		m++;
	  }
	  while(is_num(data[indexd][j+m])){
		m++;result=1;
	  }
	  if(data[indexd][j+m]=='.'&&result){
		m++;
		while(is_num(data[indexd][j+m])){
			m++;
		}
	  }
	  if(data[indexd][j+m]=='e'){
		m++;   
		while(is_num(data[indexd][j+m])){
			m++;
		}
	  }
	  if(result){
			j+=m;
			c[indexc]=20;
			indexc++;
	  }
return result;
}

bool two_str(int s){//计算>=等字符
    bool result=0;
  if(demo[s][0]==data[indexd][j]&&j+2<data[indexd].size()&&demo[s][1]==data[indexd][j+1]){
	result=1;
  
  }
 
  if(result){
		j+=2;
		c[indexc]=s;
		indexc++;
  }
	return result;

}
bool other_str(){//判断其他变量名
	bool result=0;
	while(j<data[indexd].size()&&(is_num(data[indexd][j])||is_letter(data[indexd][j]))){
		j++;
		result=1;
	}
	if(result){
			c[indexc-1]=10;
		    indexc++;
	}

 return result;
}
bool cmpstr(int s){//判断是否为第s个关键词
  bool result=1;
  for(int m=0;m<demo[s].size()&&j+m<data[indexd].size();m++){
      if(demo[s][m]!=data[indexd][j+m]){
		result=0;
		break;
	  }	
  
  }
 
  if(result &&!is_letter(data[indexd][j+m+1])&&!is_num(data[indexd][j+m+1])){
		j+=m;
		c[indexc]=s;
		indexc++;
  }else{
	result=0;
  }
	return result;
}

void compare(){//路由
	bool result;
	switch(data[indexd][j]){
		 case 'm':
			 result=cmpstr(1);
			 if(result){
				break;
			 }
		 case 'i':
				result=cmpstr(2);
				if(result){
					break;
				 }
				result=cmpstr(6);
				if(result){
					break;
				 }
		 case 'f':
			 result=cmpstr(3);
			 if(result){
				break;
			 }
		 case 'd':
			 result=cmpstr(4);
			 if(result){
				break;
			 }
			 result=cmpstr(8);
			 if(result){
				break;
			 }
		 case 'c':
			result=cmpstr(5);
				if(result){
					break;
			 }
		 case 'e':
			result=cmpstr(7);
				if(result){
					break;
			 }
				
		case 'w':
			result=cmpstr(9);
				if(result){
					break;
			 }
			
		case '='://==
				result = two_str(36);
				if(result){
					break;
				}
				c[indexc]=21;
				j++;
				indexc++;
				break;
		case '+'://单独处理
			if(indexc>0&&(c[indexc-1]==22||c[indexc-1]==23||c[indexc-1]==24||c[indexc-1]==225)){
			
			}else{
				//result=two_str();
				c[indexc]=22;
				indexc++;
				j++;
				break;	
			}
		case '-'://单独处理
			if(indexc>0&&(c[indexc-1]==22||c[indexc-1]==23||c[indexc-1]==24||c[indexc-1]==225)){
			
			}else{
				c[indexc]=23;
				indexc++;
				j++;
				break;
			}
		case '*':
				c[indexc]=24;
				indexc++;
				j++;
				break;
		case '/':
				c[indexc]=25;
				indexc++;
				j++;
				break;
		case '(':
				c[indexc]=26;
				indexc++;
				j++;
				break;
		case ')':
				c[indexc]=27;
				indexc++;
				j++;
				break;

		case '{':
				c[indexc]=28;
				indexc++;
				j++;
				break;
		case '}':
				c[indexc]=29;
				indexc++;
				j++;
				break;

		case ',':
				c[indexc]=30;
				indexc++;
				j++;
				break;
		case ';':
				c[indexc]=31;
				indexc++;
				j++;
				break;
		case '>'://///>=
			    result = two_str(33);
				if(result){
					break;
				}
				c[indexc]=32;
				indexc++;
				j++;
				break;
		case '<':
			    result = two_str(35);//<=
				if(result){
					break;
				}
				c[indexc]=34;
				indexc++;
				j++;
				break;
		case '!'://///!=
			    result = two_str(37);
				if(result){
					break;
				}
		case '\n':j++;
			   break;
        default:
			
			if(is_bit2()){
				break;
			}
			if(other_str()){
				 break;
			}else{
				c[indexc]=-34;
				indexc++;
			}
		 }


}


int main(){

demo[0]="#",
demo[1]="main",
demo[2]="int",
demo[3]="float",
demo[4]="double",
demo[5]="char",
demo[6]="if",
demo[7]="else",
demo[8]="do",
demo[9]="while",
demo[10]="l(l|d)*",
demo[20]="( +|-|ε ) dd*(.dd* | ε)( e ( +|-|ε ) dd*|ε)",
demo[21]="=",
demo[22]="+",
demo[23]="- ",
demo[24]="*",
demo[25]="/",
demo[26]="(",
demo[27]=")",
demo[28]="{",
demo[29]="}",
demo[30]=",",
demo[31]=";",
demo[32]=">",
demo[33]=">=",
demo[34]="<",
demo[35]="<=",
demo[36]="==",
demo[37]="!=";


	
	while(cin>>data[i]&&data[i][data[i].size()-1]!='#'){
	//	cout<<Data[i][Data[i].length()-1]<<endl;
		i++;
	}
	 int n=i;

	 for(indexd=0;indexd<=n;indexd++){
		 for (j=0;j<data[indexd].size();j++){
			//cout<<Data[i][j]<<endl;
			 compare();
			 cout<<data[indexd][j]<<"  "<<c[indexc]<<endl;
		 
		 } 
	 }
     for(i=0;i<38;i++){
		 for(int q=0;q<38;q++){
			ans[i][q]=0;
		 }
	 }
	 for(i=0;i<=indexc;i++){
		cout<<c[i]<<endl;
	 }






return 0;
}