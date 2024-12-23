#include<iostream>
#include<vector>
using namespace std;
void DFS(int dinh, vector<vector<int> >&DSke, vector<bool>&daTham){
	daTham[dinh] = true;
	cout<<dinh<<" ";
	for(size_t i = 0; i < DSke[dinh].size(); i++){
			int dinhKe = DSke[dinh][i];
			if(!daTham[dinhKe]){
				DFS(dinhKe, DSke, daTham);
			}
		}
}
int main(){
	int soDinh, soCanh;
	cout<<"Nhap so dinh va so canh: "; cin>>soDinh>>soCanh;
	vector<vector<int> > DSke(soDinh+1);
	vector<bool> daTham(soDinh+1, false);
	cout<<"Nhap cac canh(a, b):\n";
	for(int i = 0; i < soCanh; i++){
		int a, b;
		cin>>a>>b;
		DSke[a].push_back(b);
		DSke[b].push_back(a);
	}
	int dinhBD;
	cout<<"Nhap dinh bat dau: "; cin>>dinhBD;
	cout<<"Duyet DFS: ";
	DFS(dinhBD, DSke, daTham);
	cout<<endl;
	return 0;
}