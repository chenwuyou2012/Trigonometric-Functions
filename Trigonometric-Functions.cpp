#include<iostream>
#include<math.h>
#include<string>
#include<windows.h>
using namespace std;
const double pi=acos(-1);
inline double ssin(double x){
	double res=sin(x);
	if(fabs(res)<=1e-6) return 0;
	return res;
}
inline double scos(double x){
	double res=cos(x);
	if(fabs(res)<=1e-6) return 0;
	return res;
}
inline double stan(double x){
	double res=tan(x);
	if(fabs(res)<=1e-6) return 0;
	return res;
}
bool test(double x){
	double num=stan(x);
	if(fabs(num)>1e15) return false;
	return true;
}
int main(){
	while(true){
		system("cls");
		string x;
		cout<<"三角函数模拟运算器"<<endl;
		cout<<"author:Chen Wuyou on 25th March 2026"<<endl;
		cout<<"请选择弧度制还是角度制?"<<endl;
		cout<<"你可以输入deg表示角度制,输入rad表示弧度制,输入ecs结束"<<endl;
		cout<<"请输入文本,并按下回车"<<endl;
		while(true){
			getline(cin,x);
			if(x=="esc"||x=="rad"||x=="deg") break;
			cout<<"你的输入不符合规定,请输入文本,并按下回车"<<endl;
		}
		bool rad=false;
		if(x=="esc") break;
		if(x=="rad") rad=true;
		while(true){
			cout<<"请输入你要求的三角函数值(在总共15位之内),并按下回车,当然你可以输入esc重开"<<endl;
			cout<<"请输入文本,并按下回车"<<endl;
			cin>>x;
			if(x=="esc") break;
			bool cmp=false;
			int total=0,tot=0;
			for(int i=0;i<x.length();total+=x[i]=='.',tot+=x[i]=='-',i++) if(!(('9'>=x[i]&&x[i]>='0')||x[i]=='.'||x[i]=='-')) cmp=true;
			if(cmp||total>=2||tot>=2||(tot==1&&x[0]!='-')){
				cout<<"你的输入不符合规定,请输入文本,并按下回车"<<endl;
				continue;
			}
			double y=0,eps=1;
			bool zero=false;
			for(int i=0;i<x.length();i++){
				if(x[i]=='-') continue;
				if(x[i]=='.')zero=true;
				else if(!zero) y=y*10+x[i]-'0';
				else eps=eps*0.1,y=y+(x[i]-'0')*eps;
			}
			if(tot) y=-y;
			if(!rad) y=y/180.0*pi;
			cout<<"都只是近似值,若tan值非常大,可能说明它没意义"<<endl;
			cout<<"sin "<<x<<" = "<<ssin(y)<<endl;
			cout<<"cos "<<x<<" = "<<scos(y)<<endl;
			if(test(y)) cout<<"tan "<<x<<" = "<<stan(y)<<endl;
			else cout<<"tan "<<x<<" 无意义"<<endl;
			if(!rad) y=y/pi*180.0;
			if(-1.0<=y&&y<=1.0){
				if(!rad) cout<<"arcsin "<<x<<" = "<<asin(y)/pi*180.0<<endl,
				cout<<"arccos "<<x<<" = "<<acos(y)/pi*180.0<<endl;
				else cout<<"arcsin "<<x<<" = "<<asin(y)<<endl,
				cout<<"arccos "<<x<<" = "<<acos(y)<<endl;
			}
		} 
	}
	
	return 0;
}
