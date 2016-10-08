#include <fs/fs.hpp>

STRING combinePath(char *a, char *b) {
    return sprintf("%s/%s", a, b);
}