#include "../include/struct_constructors.h"

int main(){
    int niters = 10;
    int nstates = 20;

    MPVIResults results{niters, nstates};

    for (int i_step=0; i_step<niters; i_step++){
        VectorXd new_means = VectorXd::Random(nstates);
        MatrixXd new_cov = MatrixXd::Random(nstates, nstates);
        results.update_data(new_means, new_cov);
    }

    results.print_data(5);

    results.save_data("mean.csv", "cov.csv");
    return 0;
}