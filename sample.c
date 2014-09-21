#include "Python.h"

/* Function of two integers returning integer */

PyDoc_STRVAR(sample_foo_doc,
"foo(i,j)\n\
\n\
Return the sum of i and j.");

static PyObject *
sample_foo(PyObject *self, PyObject *args)
{
    long i, j;
    long res;
    if (!PyArg_ParseTuple(args, "ll:foo", &i, &j))
        return NULL;
    res = i+j; /* XXX Do something here */
    return PyLong_FromLong(res);
}


/* List of functions defined in the module */

static PyMethodDef sample_methods[] = {
    {"foo",             sample_foo,         METH_VARARGS,
        sample_foo_doc},
    {NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
"This is a template module just for instruction.");

/* Initialization function for the module (*must* be called PyInit_xx) */


static struct PyModuleDef samplemodule = {
    PyModuleDef_HEAD_INIT,
    "sample",
    module_doc,
    -1,
    sample_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit_sample(void)
{
    PyObject *m = NULL;

    /* Create the module and add the functions */
    m = PyModule_Create(&samplemodule);
    if (m == NULL)
        goto fail;

    return m;
 fail:
    Py_XDECREF(m);
    return NULL;
}
