/* kvadr_head.h
* properties for Square equations solver */

/*!\mainpage
 *
 *
 *
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

/// \brief constant for double number comparisons
#define accuracy 0.00001

//! \enum ROOTS
//! \brief Enum results.
//!
//! \details An enum with all possible number of roots.
enum ROOTS {
    ZERO_ROOTS = 0,
    ONE_ROOT ,
    TWO_ROOTS,
    INF_ROOTS,
};

//! \struct equation_data [kvadr_head.h]
//! \brief Structure of values.
//!
//! \details Structure which consists of equation's coefficients and roots for debugging purposes.
struct equation_data {
    /*!Coefficient with x^2 */double a;
    /*!Coefficient with x */double b;
    /*!A free coefficient. */double c;
    /*!First expected root. */double x1_expect;
    /*!Second expected root. */double x2_expect;
    /*!Expected number of roots*/int num_expect;
};

//! \brief An enter function.
//! \param a Coefficient with x^2.
//! \param b Coefficient with x.
//! \param c A free coefficient.
//!
//! \details This function allows user to enter coefficients of square equation.
void enter(double* a, double* b, double* c);

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

//! \brief Linear equations solver.
//! \param b Coefficient with b.
//! \param c Coefficient with c.
//! \return The value of x.
//!
//! \details This function solves linear equations(bx + c = 0).
double solve_linear(double b, double c);

//! \brief Result output
//! \param num The number of roots
//! \param x1 The first root
//! \param x2 The second root(if exists)
//!
//! \details This function displays x1 and x2 root values if num = 2, x1 root value if num = 1, "No solutions" if num = 0
//! Error if num is equal to anything else
void result(int num, double x1, double x2);

//! \brief A check function
//! \param a Coefficient with x^2.
//! \param b Coefficient with x.
//! \param c A free coefficient.
//! \param x1_expect First expected root of equation.
//! \param x2_expect Second expected root of equation.
//! \param num_expect Expected number of roots.
//!
//! \details This function checks equation_solver work by coefficients a, b, c. If the equations_solver function gave incorrect
//! x1 and x2 (order is not important) then it displays a, b, c values, x1, x2 and num from equation_solver,
//! expected x1, x2 and num
void check_equation(double a, double b, double c, double x1_expect, double x2_expect, int num_expect);

//! \brief Unit test function
//!
//! \details This function contains some reference coefficients a, b, c and roots x1, x2 for ax^2 + bx + c = 0 equation type.
//! It sends it to check_equation
void unit_test(void);


