/* kvadr_head.h
* properties for Square equations solver */

//#define DEBUG  //to debug uncomment "#define Debug"

/*!\mainpage Square equations solver
 *
 * This program can solve the second order equations.
 *
 * It was written for education purposes.
 *
 * ver. release 1.0
 *
 * ©Sovus_tartar
 */



#define TRUE 1
#define FALSE 0

/// \brief constant for double number comparisons
#define ACCURACY 0.00001

//! \enum ROOTS
//! \brief Enum results.
//!
//! \details An enum with all possible number of roots.
enum ROOTS {
    INF_ROOTS = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
};

//! \struct equation_data [kvadr_head.h]
//! \brief Structure of values.
//!
//! \details Structure which consists of equation's coefficients and roots for debugging purposes.
struct equation_data {
    /*!Coefficient with x^2 */    double a;
    /*!Coefficient with x */      double b;
    /*!A free coefficient. */     double c;
    /*!First expected root. */    double x1_expect;
    /*!Second expected root. */   double x2_expect;
    /*!Expected number of roots*/ int num_expect;
};

//! \brief An enter function.
//! \param a Coefficient with x^2.
//! \param b Coefficient with x.
//! \param c A free coefficient.
//!
//! \details This function allows user to enter coefficients of square equation.
void coefficients_input(double* a, double* b, double* c);

//! \brief Equations solver function.
//! \param a Coefficient with x^2.
//! \param b Coefficient with x.
//! \param c A free coefficient.
//! \param x1 First root of equation.
//! \param x2 Second root of equation.
//! \return Number of roots of equation.
//!
//! \details This function solves square equations.
int equation_solver(double a, double b, double c, double* x1, double* x2);

//! \brief Comparison function.
//! \param val_1 The first value of double.
//! \param val_2 The second value of double.
//! \return TRUE if val_1 = val_2, FALSE if val_1 != val_2.
//!
//! \details This function comparisons double numbers according by accuracy constant. It also can compare NAN values.
char is_equal(double val_1, double val_2);

//! \brief Linear equation solver.
//! \param b Coefficient with x^1.
//! \param c A free coefficient.
//! \return The value of root.
//!
//! \details This function solves linear equations(bx + c = 0).
double solve_linear(double b, double c);

//! \brief Roots output
//! \param root_number The number of roots
//! \param x1 The first root
//! \param x2 The second root(if it does not exist you still have to send a parameter)
//!
//! \details This function displays x1 and x2 root values if root_number = 2, x1 root value if root_number = 1,
//! "No solutions" if root_number = 0,
//! "Unknown Error: unexpected number of roots" if root_number is equal to anything else
void print_roots(int root_number, double x1, double x2);

//! \brief A check function
//! \param a Coefficient with x^2.
//! \param b Coefficient with x^1.
//! \param c A free coefficient.
//! \param x1_expect First expected root of equation.
//! \param x2_expect Second expected root of equation.
//! \param num_expect Expected number of roots.
//!
//! \details This function checks equation_solver work by coefficients a, b, c. If the equations_solver function give incorrect
//! x1 and x2 (order is not important) then it displays a, b, c values, x1, x2 and num from equation_solver,
//! expected x1, x2 and num
void check_equation(double a, double b, double c, double x1_expect, double x2_expect, int num_expect);

//! \brief Unit test function
//!
//! \details This function contains some reference coefficients a, b, c and roots x1, x2 for ax^2 + bx + c = 0 equation type.
//! It sends it to check_equation
void unit_test(void);

//! \brief Clean buffer function
//!
//! \details This function cleans the stdio buffer.
void clean_buffer(void);

//! \brief Square equation print function
//! \param a Coefficient with x^2
//! \param b Coefficient with x^1
//! \param c Coefficient with x^0
//! \details This function prints square equation(ax^2 + bx + x = 0) from it's coefficients.
void equation_output(double a, double b, double c);

//! \brief Variable input function
//! \param coefficient pointer to coefficient
//! \param coef_letter letter of coefficient
//! \return 1 if input was succesfull, 0 if it wasn't
//! \details This function prints "Enter <coefficient name>:" and waits for user's input, then it goes to a new line.
//! If input was successful returns 1, else returns 0.
int variable_input(double* coefficient, int coef_letter);

//! \brief The user interface function
//! \details This is a user interface function which lets user interact with the program
void user_interface(void);

//! \brief The exit program function.
//! \details This function lets user to see program's output in a terminal and proposes to exit by pressing
//! any key.
void program_exit(void);

//! \brief The number input check function
//! \param input string to check
//! \return FALSE if there are errors in line, TRUE if not
//! \details This function checks, if the string contains any symbols but numbers, '.' and whitespace characters
int input_check(char* input);
