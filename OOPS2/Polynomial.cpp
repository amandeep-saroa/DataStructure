/*
Code : Polynomial Class

Implement a polynomial class, with the following properties and functions.
Properties :
1. An integer array (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.

Functions :
1. Default constructor
2. Copy constructor

3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, 
increase the capacity accordingly and add then set the required coefficient. 
If the degree is within limits, then previous coefficient value is replaced by given coefficient value

4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases

Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)

Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5

Sample Input 2 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
2
Sample Output 2 :
-4x0 -1x1 3x2 1x3 -4x5

Sample Input 3 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
3
Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8
*/


#include<iostream>
#include<algorithm>
using namespace std;

class Polynomial
{

    
    public:

        int *degCoeff;      // Name of your array (Don't change this)
        int size;
        
        //default constructor
        Polynomial(){

            
            this -> degCoeff = new int[6];
            this -> size = 5;

        };

        //para constructor

        Polynomial(int size)
        {
            
            degCoeff = new int[size + 1];
            this -> size = size;
            

        }

        // copy contructor

        Polynomial( Polynomial const &poly1)
        {
            int *newdegCoeff = new int[poly1.size + 1];
            for(int i = 0; i <= poly1.size ; i++)
            {

                newdegCoeff[i] = poly1.degCoeff[i];

            }

                this -> degCoeff = newdegCoeff;
                this -> size = poly1.size;

        }

        //methods

        void setCoefficient(int deg , int Coeff)
        {
            if(deg > size)
            {
                
                int newSize = deg;
                int *newdegCoeff = new int[newSize + 1];

                for(int i = 0; i <= size; i++)
                {

                        newdegCoeff[i] = degCoeff[i];
                }

                this -> degCoeff = newdegCoeff;
                this -> size = newSize;
                degCoeff[deg] = Coeff;

            }

            else
            {

                degCoeff[deg] = Coeff;

            }
            

        }

        // methods
        // operator function to add two polynomial

        Polynomial operator+(Polynomial const &poly2)
        {

            int newSize = max(this->size , poly2.size);
            Polynomial resultant(newSize);
            for(int i = 0; i <= newSize; i++)
            {

                if(i <= size && i <= poly2.size)
                {
                    
                    resultant.degCoeff[i] = this -> degCoeff[i] + poly2.degCoeff[i];

                }
                else if(i <= size)
                {

                    resultant.degCoeff[i] = this -> degCoeff[i];

                }
                else
                {

                    resultant.degCoeff[i] = poly2.degCoeff[i];

                }
                
            }

            return resultant;
            

        }

        Polynomial operator-(Polynomial& poly2)
        {


            int newSize = max(this->size , poly2.size);
            Polynomial resultant(newSize);
            for(int i = 0; i <= newSize; i++)
            {

                if(i <= size && i <= poly2.size)
                {
                    
                    resultant.degCoeff[i] = degCoeff[i] - poly2.degCoeff[i];

                }
                else if(i <= size)
                {

                    resultant.degCoeff[i] = this->degCoeff[i];

                }
                else
                {

                    resultant.degCoeff[i] = -poly2.degCoeff[i];

                }
                
            }

            return resultant;
            

        }

        Polynomial operator*(Polynomial& poly2)
        {

            
            int newSize = this -> size + poly2.size;
            Polynomial resultant(newSize);
            for(int i = 0; i <= this -> size; i++)
            {
                
                for(int j = 0; j <= poly2.size; j++)
                resultant.degCoeff[i + j] = resultant.degCoeff[i+j] + this -> degCoeff[i+j] * poly2.degCoeff[j];
            }

            return resultant;
            

        }

        void operator=(Polynomial const &poly2)
        {

            int *newdegCoeff = new int[poly2.size + 1];
            
            for(int i = 0; i < poly2.size; i++)
            {

                newdegCoeff[i] = poly2.degCoeff[i];

            }

            this -> degCoeff = newdegCoeff;
            this -> size = poly2.size;
            
            

        }


        void print()
        {

            for(int i = 0 ; i <= this -> size; i++)
            {

                if(degCoeff[i] != 0)
                {
                    cout << this -> degCoeff[i] << "x" << i << " ";

                }

                

            }

            cout << endl;

        }
        

};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
