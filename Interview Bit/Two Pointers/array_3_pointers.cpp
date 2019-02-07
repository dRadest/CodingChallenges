/*
* https://www.interviewbit.com/problems/array-3-pointers/
*
* You are given 3 arrays A, B and C. All 3 of the arrays are sorted.
*
* Find i, j, k such that :
* max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
* Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))
*/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int p=A.size();
    int q=B.size();
    int r=C.size();
    int i=0, j=0, k=0;
    int ans=INT_MAX;
    int temp1,temp2,temp3;
    while(i<p && j<q && k<r){

        temp1=A[i]-B[j];
        temp2=B[j]-C[k];
        temp3=C[k]-A[i];
        ans=min(ans,max(abs(temp1),max(abs(temp2),abs(temp3))));
        if(abs(temp1)>=abs(temp2) && abs(temp1)>=abs(temp3)){
            if(temp1>0){
                j++;
            }
            else i++;
        }
        else if(abs(temp2)>=abs(temp3) && abs(temp2)>=abs(temp1)){
            if(temp2>0){
                k++;
            }
            else j++;
        }
        else if(abs(temp3)>=abs(temp2 && abs(temp3)>=abs(temp1)){
            if(temp3>0){
                i++;
            }
            else k++;
        }
    }
    return ans;
}
