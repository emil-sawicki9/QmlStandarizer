#ifndef GLOBALS_H
#define GLOBALS_H

#define CYAN(x) "\033[1;36m" << x << "\033[0m"
#define BLUE(x) "\033[1;34m" << x << "\033[0m"
#define RED(x) "\033[1;31m" << x << "\033[0m"
#define GREEN(x) "\033[1;32m" << x << "\033[0m"

#define CONDITIONAL_LOG() if (m_log) qDebug()

#endif // GLOBALS_H
