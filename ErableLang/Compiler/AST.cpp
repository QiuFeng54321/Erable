#include <utility>

#include <utility>

#include <utility>


//
// Created by Qiufeng54321 on 2019-06-19.
// Copyright (c) Qiufeng54321 All rights reserved.
//

#include "AST.hpp"
#include <sstream>

namespace Erable::Compiler::AST {

    int NameTree::currentId = 0;

    NameTree tree(Name({{NameType::NAMESPACE, "__default"}}), nullptr);

    Name::Name(std::vector<NameNode> nodes) : nodes(std::move(nodes)) {}

    std::ostream &operator<<(std::ostream &os, const Name &name) {
        for (auto node : name.nodes) {
            os << ((char) node.type) << name;
        }
        return os;
    }

    Name::operator std::string() {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    Name::Name(std::vector<NameNode> parent, NameNode node) {
        auto cpy(std::move(parent));
        cpy.push_back(node);
        nodes = cpy;
    }

    const std::vector<NameNode> &Name::getNodes() const {
        return nodes;
    }

    void Name::setNodes(const std::vector<NameNode> &nodes) {
        Name::nodes = nodes;
    }

    bool Name::operator==(const Name &rhs) const {
        return nodes == rhs.nodes;
    }

    bool Name::operator!=(const Name &rhs) const {
        return !(rhs == *this);
    }

    bool Name::matchEnd(NameType type, std::string name) {
        if (not nodes.empty()) {
            auto n = nodes[nodes.size() - 1];
            return n == NameNode{type, std::move(name)};
        }
        return false;
    }

    NameTree::NameTree(std::vector<NameTree *> tree, Name name, NameTree *parent)
            : tree(std::move(tree)), name(std::move(name)), parent(parent), id(currentId++) {}

    NameTree::NameTree(Name name, NameTree *parent) : name(std::move(name)), parent(parent), id(currentId++) {}

    void NameTree::add(NameTree *nameTree) {
        nameTree->setParent(this);
        tree.push_back(nameTree);
    }

    void NameTree::add(NameType type, std::string strName) {
        this->add(new NameTree(Name(this->name.getNodes(), {type, std::move(strName)}), this));
    }

    NameTree *NameTree::find(const Name &n) {
        if (this->tree.empty()) {
            return (name == n ? this : nullptr);
        }
        for (auto *tr : tree) {
            auto *ret = tr->find(n);
            if (ret)return ret;
        }
        return nullptr;
    }

    NameTree *NameTree::findWithScope(NameType type, std::string n) {
        if (parent == nullptr) {
            if (name.matchEnd(type, n))return this;
            for (auto *subTree : this->tree) {
                if (subTree->name.matchEnd(type, n))return subTree;
            }
            return nullptr;
        }
        return parent->findWithScope(type, n);
    }

    NameTree *NameTree::getParent() const {
        return parent;
    }

    void NameTree::setParent(NameTree *parent) {
        NameTree::parent = parent;
    }

    ASTNode::ASTNode(Parser *parent) : parent(parent) {}

    bool NameNode::operator==(const NameNode &rhs) const {
        return type == rhs.type &&
               name == rhs.name;
    }

    bool NameNode::operator!=(const NameNode &rhs) const {
        return !(rhs == *this);
    }
}