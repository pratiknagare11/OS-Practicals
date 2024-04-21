#include<bits/stdc++.h>

using namespace std;

void ffit(vector<int> blocks, vector<int> process, int bsize, int psize){
    vector<int> bcopy = blocks;
    vector<int> processalloc(psize, -1);
    vector<int> blockalloc(bsize, -1);
    
    for(int i=0; i<psize; i++){
        for(int j=0; j<bsize; j++){
            if(bcopy[j] >= process[i] && blockalloc[j] == -1){
                blockalloc[j] = 1;
                processalloc[i] = j;
                bcopy[j] -= process[i];
                break;
            }
        }
    }

    cout<<"P. No \t Process size \t Block No \t Block size\n";
    for(int i=0; i<psize; i++){
        cout<<"P"<<i<<"\t\t "<<process[i]<<"\t\t";
        if(processalloc[i] != -1)
            cout << "B" << processalloc[i] << "\t\t" << blocks[processalloc[i]] << "\n";
        else
            cout << "Not Allocated\n"; 
    }
    cout<<endl;
}

void bfit(vector<int> blocks, vector<int> process, int bsize, int psize){
    vector<int> bcopy = blocks;
    vector<int> processalloc(psize, -1);
    vector<int> blockalloc(bsize, -1);
    

    for(int i=0; i<psize; i++){
        int bi = -1;
        for(int j=0; j<bsize; j++){
            if(bcopy[j] >= process[i] && blockalloc[j] == -1){
                if(bi == -1){
                    bi = j;
                }
                else if(bcopy[j] < bcopy[bi]){
                    bi = j;
                }
            }
        }
        if(bi != -1){
            blockalloc[bi] = 1;
            processalloc[i] = bi;
            bcopy[bi] -= process[i];
        }
    }

    cout<<"P. No \t Process size \t Block No \t Block size\n";
    for(int i=0; i<psize; i++){
        cout<<"P"<<i<<"\t\t "<<process[i]<<"\t\t";
        if(processalloc[i] != -1)
            cout << "B" << processalloc[i] << "\t\t" << blocks[processalloc[i]] << "\n";
        else
            cout << "Not Allocated\n"; 
    }
    cout<<endl;
}

void wfit(vector<int> blocks, vector<int> process, int bsize, int psize){
    vector<int> bcopy = blocks;
    vector<int> processalloc(psize, -1);
    vector<int> blockalloc(bsize, -1);
    

    for(int i=0; i<psize; i++){
        int wi = -1;
        for(int j=0; j<bsize; j++){
            if(bcopy[j] >= process[i] && blockalloc[j] == -1){
                if(wi == -1){
                    wi = j;
                }
                else if(bcopy[j] > bcopy[wi]){
                    wi = j;
                }
            }
        }
        if(wi != -1){
            blockalloc[wi] = 1;
            processalloc[i] = wi;
            bcopy[wi] -= process[i];
        }
    }

    cout<<"P. No \t Process size \t Block No \t Block size\n";
    for(int i=0; i<psize; i++){
        cout<<"P"<<i<<"\t\t "<<process[i]<<"\t\t";
        if(processalloc[i] != -1)
            cout << "B" << processalloc[i] << "\t\t" << blocks[processalloc[i]] << "\n";
        else
            cout << "Not Allocated\n";  
    }
    cout<<endl;
}

void nfit(vector<int> blocks, vector<int> process, int bsize, int psize){
    vector<int> bcopy = blocks;
    vector<int> processalloc(psize, -1);
    vector<int> blockalloc(bsize, -1);
    int j=0;

    for(int i=0; i<psize; i++){
        int start = j;
        do{
            if(bcopy[j] >= process[i] && blockalloc[j] == -1){
                blockalloc[j] = 1;
                processalloc[i] = j;
                bcopy[j] -= process[i];
                break;
            }
            j = (j+1) % bsize;
        }while(j != start);
    }

    cout<<"P. No \t Process size \t Block No \t Block size\n";
    for(int i=0; i<psize; i++){
        cout<<"P"<<i<<"\t\t "<<process[i]<<"\t\t";
        if(processalloc[i] != -1)
            cout << "B" << processalloc[i] << "\t\t" << blocks[processalloc[i]] << "\n";
        else
            cout << "Not Allocated\n";  
    }
    cout<<endl;
}

int main(){
    int blocksize;
    cout<<"Enter the total no. of  blocks: "<<endl;
    cin>> blocksize;
    vector<int> blocks(blocksize);
    cout<<"Enter the blocks: "<<endl;
    for(int i = 0; i< blocksize; i++){
        cin>>blocks[i];
    }

    int processize;
    cout<<"Enter the total no. of processes: "<<endl;
    cin>>processize;
    vector<int> process(processize);
    cout<<"Enter the processes: "<<endl;
    for(int i = 0; i< processize; i++){
        cin>>process[i];
    }
    cout<<endl;

    cout<<"First fit Allocation: "<<endl;
    ffit(blocks, process, blocksize, processize);

    cout<<"Best fit Allocation: "<<endl;
    bfit(blocks, process, blocksize, processize);

    cout<<"Worst fit Allocation: "<<endl;
    wfit(blocks, process, blocksize, processize);

    cout<<"Next fit Allocation: "<<endl;
    nfit(blocks, process, blocksize, processize);
}

//block : 100,500,200,300,600
//process : 212 417 112 426