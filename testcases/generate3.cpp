#include <iostream>
using namespace std;

int main() {
    
    cout << 100 << endl;
    
    for(int i=0; i<100; i++){
        
        cout << i << " ";
        
        for(int j=1; j<=i; j++){
            
            cout << j << " ";
            
        }
        
        cout << endl;
        
    }
    
	return 0;
}
