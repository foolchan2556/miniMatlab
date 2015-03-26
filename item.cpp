#include "item.h"

Item::Item(Workspace * workspace) : exp("")
{
        worksp = workspace;
        matrix = new Matrix(1, 1);
        matrix->isValid = false;
}

Item::~Item()
{
        delete matrix;
}

void Item::setWorkspace(Workspace * workspace)
{
        worksp = workspace;
}

/*int Item::setFtable(Ftable * pFtable)
{
        ftable = pFtable;
}*/

int Item::eval(const string & expr)
{
        exp = expr;
        delete matrix;
        int pos = 0;
        matrix = evalExp(expr, pos);
        if (matrix->isValid)
                return 0;
        else
                return -1;
}

const string & Item::expr()
{
        return exp;
}

const Matrix & Item::value()
{
        return *matrix;
}

// decompose exp into term by + -
Matrix * Item::evalExp(const string & str, int & pos)
{
    Matrix * result = evalTerm(str, pos);
    if (!result->isValid) return result;
    while (pos < str.length()) {
        char op = str[pos];
        if (op != '+' && op != '-')
            return result;
        ++pos;

        Matrix * term = evalTerm(str, pos);
        if (!term->isValid) {
            delete result;
            return term;
        }
        if (op == '+') {
            *result += *term;
        } else {
            *result -= *term;
        }
        delete term;
    }
    return result;
}

// decompose term into factor by * /

// !!!!!!!!!
// To Haolan: you should alter the *, *= and /, /= operator in matrix
//            to let it assume that 1x1 matrix is equal to a pure number
Matrix * Item::evalTerm(const string & str, int & pos)
{
    Matrix * result = evalFactor(str, pos);
    if (!result->isValid) return result;
    while (pos < str.length()) {
        char op = str[pos];
        if (op != '*' && op != '/')
            return result;
        ++pos;

        Matrix * term = evalFactor(str, pos);
        if (!term->isValid) {
            delete result;
            return term;
        }
        if (op == '*') {
            *result *= *term;
        } else {
            *result -= *term;
        }
        delete term;
    }
    return result;
}

Matrix * Item::evalFactor(const string & str, int & pos)
{
    Matrix * result = new Matrix(1, 1);
    bool negative = false;

    if (pos >= str.length()) {
        result->isValid = false;
        return result;
    }
    if (str[pos] == '-') {
        negative = true;
        ++pos;
    }

    if (pos >= str.length()) {
        result->isValid = false;
        return result;
    }
    if (str[pos] == '(') {
        ++pos;
        delete result;
        result = evalExp(str, pos);
        if (pos >= str.length()) {
            result->isValid = false;
            return result;
        }
        if (str[pos] != ')') {
            result->isValid = false;
            return result;
        }
        ++pos;
    } else if (str[pos] == '[') {
        ++pos;
        delete result;
        result = evalMatrix(str, pos);
        if (pos >= str.length()) {
            result->isValid = false;
            return result;
        }
        if (str[pos] != ']') {
            result->isValid = false;
            return result;
        }
        ++pos;
    } else {
        string token = "";
        // notice occasions that pos >= str.length()
        // get name token and judge whether it's a num/var/fun
        while (pos < str.length() && ( str[pos] == '.' || isalnum(str[pos]) )) {
            token += str[pos];
            ++pos;
        }
        double num;
        if (sscanf(token.c_str(), "%lf", &num) != 0) {
            // delete and save a single num matrix into result
            delete result;
            result = new Matrix(&num, 1, 1);
        } else {
            /*if (pos >= str.length()) {
                result->isValid = false;
                return result;
            }*/
            if (pos < str.length() && str[pos] == '(') {
                                ++pos;
                                if (pos >= str.length()) {
                                        result->isValid = false;
                                        return result;
                                }
                delete result;
                vector<Matrix> params;

                do{
                                        if (str[pos] == ',') ++pos;
                    result = evalExp(str, pos);
                    if (!result->isValid) break;
                    params.push_back(*result);
                    delete result;
                } while (pos < str.length() && str[pos] == ',');
                result = Ftable::eval(token, &params[0] , params.size());

                if (pos >= str.length()) {
                    result->isValid = false;
                    return result;
                }
                if (str[pos] != ')') {
                    result->isValid = false;
                    return result;
                }
                ++pos;

                /*vector<Matrix *>::iterator it = params.begin();
                while (it != params.end()) {
                    delete *it;
                    ++it;
                }*/
                // resolve n matrices, save them in an array, pass to ftable
                // save the result into result
            } else { // get matrix from workspace
                if (!worksp) {
                        result->isValid = false;
                        return result;
                }
                Item * item = worksp->get(token);
                if (!item) {
                        result->isValid = false;
                        return result;
                }
                delete result;
                result = new Matrix(item->value());
            }
        }
    }

    if (negative) {
        *result = -(*result);
    }
    return result;
}

Matrix * Item::evalMatrix(const string & str, int & pos)
{
    Matrix * result = new Matrix(1, 1);
    vector<double> line1;

    do {
                if (pos > str.length()) {
                        result->isValid = false;
                        return result;
                }
                if (str[pos] == ',') ++pos;
                string token = "";
        while (pos < str.length() && ( str[pos] == '.' || isdigit(str[pos]) )) {
            token += str[pos];
            ++pos;
        }
        double num;
        if (sscanf(token.c_str(), "%lf", &num) != 0) {
            line1.push_back(num);
        } else {
            result->isValid = false;
            return result;
        }
    } while (pos < str.length() && str[pos] == ',');

    size_t l = line1.size();
    vector<vector<double> > nums(1, line1);

    while (pos < str.length() && str[pos] == ';') {
                if (str[pos] == ';') ++pos;
        vector<double> line;
        do {
                        if (pos > str.length()) {
                                result->isValid = false;
                                return result;
                        }
                        if (str[pos] == ',') ++pos;
            string token = "";
            while (pos < str.length() && ( str[pos] == '.' || isdigit(str[pos]) )) {
                token += str[pos];
                ++pos;
            }
            double num;
            if (sscanf(token.c_str(), "%lf", &num) != 0) {
                line.push_back(num);
            } else {
                result->isValid = false;
                return result;
            }
            if (line.size() > l) {
                result->isValid = false;
                return result;
            }
        } while (pos < str.length() && str[pos] == ',');

        while (line.size() < l) line.push_back(0);

        nums.push_back(line);
    };

    delete result;
    result = new Matrix(nums.size(), l);
    int i=0;
    for (vector<vector<double> >::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
        int j=0;
        for (vector<double>::iterator itc = itr->begin(); itc != itr->end(); ++itc) {
            (*result)(i, j) =*itc;
            ++j;
        }
        ++i;
    }

    return result;
}

