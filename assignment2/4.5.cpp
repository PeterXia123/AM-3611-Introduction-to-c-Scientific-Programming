#include <iostream>
#include <fstream>
int main(int argc, char * argv[]) {

std::ifstream read_file("xy.dat");
    if (!read_file.is_open()) {
    return 1; }
    int number_of_rows = 0;
    while(true) {
        
        double dummy1, dummy2;
        
        read_file >> dummy1;
        
        read_file >> dummy2;
        
        if(read_file.eof()) break;
        
        number_of_rows++;
        
    }
    std::cout << "Number of rows = " << number_of_rows << "\n";
    read_file.clear();
    read_file.seekg(std::ios::beg);
    double *x = new double[number_of_rows];
    double *y = new double[number_of_rows];
    for (int i= 0; i<number_of_rows ;i++) {
        read_file >> x[i];
        read_file >> y[i];
        if(read_file.eof()) break;
    }
    read_file.close();
    
    std::ofstream write_output("two,col");
    assert(write_output.is_open());
    for(int i = 0; i<number_of_rows;i++ ){
        write_output<<x[i]<<","<<y[i]<<"\n";
    }
    write_output.close();
    return 0;
}


