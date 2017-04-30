#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int num,m,data;
    int start_from_2 = 0;
    
    cin >> num;
    
    vector<vector<int> >store(num + 1,vector<int>(num + 1,0));     // for storing the input (adjacency matrix)
    vector<int> answer(2*num);                                     // the final sequence, it is taken of size 2*num, so that we can start adding numbers from the middle and it becomes easy to add a number in the starting

    // storing the input

    for(int i=0; i<num; i++){        
        
        cin >> m;
        if(i==0 && m==0){            // checking if 1 has beaten anybody
            start_from_2 = 1;
        }
        
        for(int j=0; j<m; j++){
            
            cin >> data;
            store[i+1][data] = 1;
            
        }
        
    }
    
    int is_number_done[2001] = {0};   // for remembering that a given number is already put in the sequence
    is_number_done[0] = 1;
    
    if(start_from_2 == 0){
        for(int i=2; i<=num; i++){          // putting 1 and any corresponding number in the sequence
            if(store[1][i] == 1){
                answer[num-1] = 1;
                answer[num] = i;
                is_number_done[1] = 1;
                is_number_done[i] = 1;
                break;
            }
        }
    }
    else{
        for(int i=1; i<=num; i++){          // if 1 has not beaten anybody, we start from 2
            if(store[2][i] == 1){
                answer[num-1] = 2;
                answer[num] = i;
                is_number_done[2] = 1;
                is_number_done[i] = 1;
                break;
            }
        }
    }
    
    int end = num;                        // pointer for the end of sequence
    int start = num - 1;                  // pointer for the start of sequence
    
    
    for(int j=1; j<=num; j++){
        
        if(is_number_done[j]==0){          
            
            if(store[j][answer[start]] == 1){           // case-1
                
                answer[start - 1] = j;
                is_number_done[j] = 1;
                start = start - 1;
                
            }
            else if(store[answer[end]][j] == 1){        // case-2
                
                answer[end + 1] = j;
                is_number_done[j] = 1;
                end += 1;
                
            }
            else{                                       // case-3
                
                for(int k = start; k<end; k++){
                    
                    if(store[answer[k]][j] == 1 && store[j][answer[k + 1]] == 1){
                        
                        for(int copy = end + 1; copy> k + 1; copy--){
                            answer[copy] = answer[copy - 1];
                        }
                        
                        answer[k + 1] = j;
                        is_number_done[j] = 1;
                        end += 1;
                        break;
                    }
                    
                }
                
            }
            
        }
        
    }
    
   cout << "YES" << endl;                         // there is always a hamiltonian path in the tournament graph, so YES 
   
   for(int i=0; i<2*num; i++){
       
       if(answer[i] != 0){
            cout << answer[i] << " ";
       }
   }
   
   return 0;
   
}

