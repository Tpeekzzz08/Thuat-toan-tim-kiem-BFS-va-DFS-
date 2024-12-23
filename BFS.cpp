#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(int dinhBD, vector<vector<int> >& DSke, vector<bool>&daTham){
	queue<int>hangDoi;
	hangDoi.push(dinhBD);
	daTham[dinhBD] = true;
	cout<<"Duyet BFS: ";
	while(!hangDoi.empty()){
		int dinhHT = hangDoi.front();
		hangDoi.pop();
		cout<<dinhHT<<" ";
		for(size_t i = 0; i < DSke[dinhHT].size(); i++){
			int dinhKe = DSke[dinhHT][i];
			if(!daTham[dinhKe]){
				hangDoi.push(dinhKe);
				daTham[dinhKe] = true;
			}
		}
	}
	cout<<endl;
}
int main(){
	int soDinh, soCanh;
	cout<<"Nhap so dinh va so canh: "; cin>>soDinh>>soCanh;
	vector<vector<int> > DSke(soDinh+1);
	vector<bool> daTham(soDinh+1, false);
	cout<<"Nhap cac canh (a, b):\n";
	for(int i = 0; i < soCanh; i++){
		int a, b;
		cin>>a>>b;
		DSke[a].push_back(b);
		DSke[a].push_back(b);
	}
	int dinhBD;
	cout<<"Nhap dinh bat dau: ";
	cin>>dinhBD;
	BFS(dinhBD, DSke, daTham);
	return 0;
}