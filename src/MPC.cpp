#include "MPC.h"
#include <cppad/cppad.hpp>
#include <cppad/ipopt/solve.hpp>
#include "Eigen-3.3/Eigen/Core"

using CppAD::AD;

namespace
{
    // TODO: Set the timestep length and duration
    size_t N = 0;
    double dt = 0;
    
    // This value assumes the model presented in the classroom is used
    //
    // It was obtained by measuring the radius formed by running the vehicle in the
    // simulator around in a circle with a constant steering angle and velocity on a
    // flat terrain.
    //
    // Lf was tuned until the the radius formed by the simulating the model
    // presented in the classroom matched the previous radius.
    //
    // This is the length from front to CoG that has a similar radius.
    const double Lf = 2.67;
    
    class FG_eval
    {
    public:
        
        typedef CPPAD_TESTVECTOR(AD<double>) ADvector;
        
        // Fitted polynomial coefficients
        FG_eval(Eigen::VectorXd inCoeffs) :
        coeffs(inCoeffs)
        {
            
        }
        
        void operator()(ADvector& fg, const ADvector& vars)
        {
            // TODO: Implement MPC
            //
            // `fg` is a vector of the cost constraints
            // `vars` is a vector of variable values (state & actuators)
            //
            // NOTE: We'll probably go back and forth between this function and
            // the Solver function below.
        }
        
    private:
        
        // Fitted polynomial coefficients
        Eigen::VectorXd coeffs;
    };
}

//
// MPC class implementation
//
MPC::MPC()
{
    
}

MPC::~MPC()
{
    
}

std::vector<double> MPC::Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs)
{
    typedef CPPAD_TESTVECTOR(double) Dvector;
    
    bool ok = true;
    size_t i;
    
    // TODO: Set the number of model variables (includes both states and inputs).
    // For example: If the state is a 4 element vector, the actuators is a 2
    // element vector and there are 10 timesteps. The number of variables is:
    //
    // 4 * 10 + 2 * 9
    size_t n_vars = 0;
    
    // TODO: Set the number of constraints
    size_t n_constraints = 0;
    
    // Initial value of the independent variables.
    // SHOULD BE 0 besides initial state.
    Dvector vars(n_vars);
    for (size_t i = 0; i < n_vars; i++)
    {
        vars[i] = 0;
    }
    
    Dvector vars_lowerbound(n_vars);
    Dvector vars_upperbound(n_vars);
    // TODO: Set lower and upper limits for variables.
    
    // Lower and upper limits for the constraints
    //
    // Should be 0 besides initial state.
    Dvector constraints_lowerbound(n_constraints);
    Dvector constraints_upperbound(n_constraints);
    for (size_t i = 0; i < n_constraints; i++)
    {
        constraints_lowerbound[i] = 0;
        constraints_upperbound[i] = 0;
    }
    
    // Object that computes objective and constraints
    FG_eval fg_eval(coeffs);
    
    // NOTE: We don't have to worry about these options
    //
    // Options for IPOPT solver
    std::string options;
    
    // Uncomment this if we'd like more print information
    options += "Integer print_level  0\n";
    
    // NOTE: Setting sparse to true allows the solver to take advantage
    // of sparse routines, this makes the computation MUCH FASTER. If we
    // can uncomment 1 of these and see if it makes a difference or not but
    // if we uncomment both the computation time should go up in orders of
    // magnitude.
    options += "Sparse  true        forward\n";
    options += "Sparse  true        reverse\n";
    
    // NOTE: Currently the solver has a maximum time limit of 0.5 seconds.
    // Change this as we see fit.
    options += "Numeric max_cpu_time          0.5\n";
    
    // Place to return solution
    CppAD::ipopt::solve_result<Dvector> solution;
    
    // Solve the problem
    CppAD::ipopt::solve<Dvector, FG_eval>(options, vars, vars_lowerbound, vars_upperbound, constraints_lowerbound, constraints_upperbound, fg_eval, solution);
    
    // Check some of the solution values
    ok &= (solution.status == CppAD::ipopt::solve_result<Dvector>::success);
    
    // Cost
    auto cost = solution.obj_value;
    std::cout << "Cost: " << cost << std::endl;
    
    // TODO: Return the first actuator values. The variables can be accessed with
    // `solution.x[i]`.
    //
    // {...} is shorthand for creating a vector, so auto x1 = {1.0,2.0}
    // creates a 2 element double vector.
    return {};
}
