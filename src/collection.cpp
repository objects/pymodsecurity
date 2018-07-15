#include <pybind11/pybind11.h>
#include <modsecurity/collection/variable.h>
#include <modsecurity/collection/collection.h>

namespace py = pybind11;

using modsecurity::collection::Collection;
using modsecurity::collection::Variable;

class pyCollection : public Collection {
    public:
    using Collection::Collection;

    void store(std::string key, std::string value) override {
        PYBIND11_OVERLOAD_PURE(void, Collection, store, key, value);
    }

    bool storeOrUpdateFirst(const std::string &key, const std::string &value) override {
        PYBIND11_OVERLOAD_PURE(bool, Collection, storeOrUpdateFirst, key, value);
    }

    bool updateFirst(const std::string &key, const std::string &value) override {
        PYBIND11_OVERLOAD_PURE(bool, Collection, updateFirst, key, value);
    }

    void del(const std::string& key) override {
        PYBIND11_OVERLOAD_PURE(void, Collection, del, key);
    }

    std::unique_ptr<std::string> resolveFirst(const std::string& var) override {
        // PYBIND11_OVERLOAD_PURE(std::string*, Collection, resolveFirst, var);
        return nullptr;
    }

    // std::string* resolveFirst_wrapper(const std::string& var) {
    //     PYBIND11_OVERLOAD_PURE(std::string*, Collection, resolveFirst, var);
    // }

    void resolveSingleMatch(const std::string& var, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD_PURE(void, Collection, resolveSingleMatch, var, l);
    }
    
    void resolveMultiMatches(const std::string& var, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD_PURE(void, Collection, resolveMultiMatches, var, l);
    }

    void resolveRegularExpression(const std::string& var, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD_PURE(void, Collection, resolveRegularExpression, var, l);
    }

    void store(std::string key, std::string compartment, std::string value)  override {
        PYBIND11_OVERLOAD(void, Collection, store, key, compartment, value);
    }

    void store(std::string key, std::string compartment, std::string compartment2, std::string value) override {
        PYBIND11_OVERLOAD(void, Collection, store, key, compartment, compartment2, value);
    }

    bool storeOrUpdateFirst(const std::string &key, std::string compartment, const std::string &value) override {
        PYBIND11_OVERLOAD(bool, Collection, storeOrUpdateFirst, key, compartment, value);
    }

    bool storeOrUpdateFirst(const std::string &key, std::string compartment, std::string compartment2, const std::string &value) override {
        PYBIND11_OVERLOAD(bool, Collection, storeOrUpdateFirst, key, compartment, compartment2, value);
    }

    bool updateFirst(const std::string &key, std::string compartment, const std::string &value) override {
        PYBIND11_OVERLOAD(bool, Collection, updateFirst, key, compartment, value);
    }

    bool updateFirst(const std::string &key, std::string compartment, std::string compartment2, const std::string &value) override {
        PYBIND11_OVERLOAD(bool, Collection, updateFirst, key, compartment, compartment2, value);
    }

    void del(const std::string& key, std::string compartment) override {
        PYBIND11_OVERLOAD(void, Collection, del, key, compartment);
    }

    void del(const std::string& key, std::string compartment, std::string compartment2) override {
        PYBIND11_OVERLOAD(void, Collection, del, key, compartment, compartment2);
    }

    // std::string* resolveFirst_wrapper(const std::string& var, std::string compartment) {
    //     PYBIND11_OVERLOAD_INT(std::string*, Collection, resolveFirst, var, compartment);
    //     return Collection::resolveFirst(var, compartment).release();
    // }

    // std::string* resolveFirst_wrapper(const std::string& var, std::string compartment, std::string compartment2) {
    //     PYBIND11_OVERLOAD_INT(std::string*, Collection, resolveFirst, var, compartment, compartment2);
    //     return Collection::resolveFirst(var, compartment, compartment2).release();
    // }

    void resolveSingleMatch(const std::string& var, std::string compartment, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD(void, Collection, resolveSingleMatch, var, compartment, l);
    }

    void resolveSingleMatch(const std::string& var, std::string compartment, std::string compartment2, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD(void, Collection, resolveSingleMatch, var, compartment, compartment2, l);
    }

    void resolveMultiMatches(const std::string& var, std::string compartment, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD(void, Collection, resolveMultiMatches, var, compartment, l);
    }

    void resolveMultiMatches(const std::string& var, std::string compartment, std::string compartment2, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD(void, Collection, resolveMultiMatches, var, compartment, compartment2, l);
    }

    void resolveRegularExpression(const std::string& var, std::string compartment, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD(void, Collection, resolveRegularExpression, var, compartment, l);
    }

    void resolveRegularExpression(const std::string& var, std::string compartment, std::string compartment2, std::vector<const Variable *> *l) override {
        PYBIND11_OVERLOAD(void, Collection, resolveRegularExpression, var, compartment, compartment2, l);
    }
};

void init_collection(py::module& m)
{
    py::module collection_module = m.def_submodule("collection");

    py::class_<Collection, pyCollection>(collection_module, "Collection")
        .def(py::init<>())
        .def("store", py::overload_cast<std::string, std::string>(&Collection::store))
        .def("store", py::overload_cast<std::string, std::string, std::string>(&Collection::store))
        .def("store", py::overload_cast<std::string, std::string, std::string, std::string>(&Collection::store))
        .def("storeOrUpdateFirst", py::overload_cast<const std::string &, const std::string &>(&Collection::storeOrUpdateFirst))
        .def("storeOrUpdateFirst", py::overload_cast<const std::string &, std::string, const std::string &>(&Collection::storeOrUpdateFirst))
        .def("storeOrUpdateFirst", py::overload_cast<const std::string &, std::string, std::string, const std::string &>(&Collection::storeOrUpdateFirst))
        .def("updateFirst", py::overload_cast<const std::string &, const std::string &>(&Collection::updateFirst))
        .def("updateFirst", py::overload_cast<const std::string &, std::string, const std::string &>(&Collection::updateFirst))
        .def("updateFirst", py::overload_cast<const std::string &, std::string, std::string, const std::string &>(&Collection::updateFirst))
        .def("del", py::overload_cast<const std::string &>(&Collection::del))
        .def("del", py::overload_cast<const std::string &, std::string>(&Collection::del))
        .def("del", py::overload_cast<const std::string &, std::string, std::string>(&Collection::del))
        // .def("resolveFirst", py::overload_cast<const std::string&>(&pyCollection::resolveFirst_wrapper))
        // .def("resolveFirst", py::overload_cast<const std::string&, std::string>(&pyCollection::resolveFirst_wrapper))
        // .def("resolveFirst", py::overload_cast<const std::string&, std::string, std::string>(&pyCollection::resolveFirst_wrapper))
        .def("resolveSingleMatch", py::overload_cast<const std::string &, std::vector<const Variable *> *>(&Collection::resolveSingleMatch))
        .def("resolveSingleMatch", py::overload_cast<const std::string &, std::string, std::vector<const Variable *> *>(&Collection::resolveSingleMatch))
        .def("resolveSingleMatch", py::overload_cast<const std::string &, std::string, std::string, std::vector<const Variable *> *>(&Collection::resolveSingleMatch))
        .def("resolveMultiMatches", py::overload_cast<const std::string &, std::vector<const Variable *> *>(&Collection::resolveMultiMatches))
        .def("resolveMultiMatches", py::overload_cast<const std::string &, std::string, std::vector<const Variable *> *>(&Collection::resolveMultiMatches))
        .def("resolveMultiMatches", py::overload_cast<const std::string &, std::string, std::string, std::vector<const Variable *> *>(&Collection::resolveMultiMatches))
        .def("resolveRegularExpression", py::overload_cast<const std::string &, std::vector<const Variable *> *>(&Collection::resolveRegularExpression))
        .def("resolveRegularExpression", py::overload_cast<const std::string &, std::string, std::vector<const Variable *> *>(&Collection::resolveRegularExpression))
        .def("resolveRegularExpression", py::overload_cast<const std::string &, std::string, std::string, std::vector<const Variable *> *>(&Collection::resolveRegularExpression))
        .def_readwrite("m_name", &Collection::m_name);
}