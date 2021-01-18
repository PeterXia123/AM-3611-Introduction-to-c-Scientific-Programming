#include <iostream>
#include <fstream>
int main(int argc, char * argv[]) {

std::ifstream read_file("x_and_y.dat");
    if (!read_file.is_open()) {
    return 1; }
    int number_of_rows = 0;
    while(true) {
        
        double dummy1, dummy2, dummy3, dummy4;
        
        read_file >> dummy1 >> dummy2;
        
        read_file >> dummy3 >> dummy4;
        
        if(read_file.eof()) break;
        
        number_of_rows++;
        
    }
    std::cout << "Number of rows = " << number_of_rows << "\n";
        read_file.close();
        return 0;
}

// the problem is that right after the second iteration. we haven't reach the EOF because the EOF mark havn't been read yet. so we still carry on to the next iteration, so the num of rows  plus 1 to 3.
// my solution is test the  EOF right before add row。 so even though we go to the third iteration. we can still
//reach the eof and break it in time

