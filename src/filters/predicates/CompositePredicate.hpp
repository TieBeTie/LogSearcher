#pragma once
#include "Predicate.hpp"
#include <memory>

class AndPredicate : public Predicate {
public:
    AndPredicate(std::unique_ptr<Predicate> left, std::unique_ptr<Predicate> right)
        : m_left(std::move(left)), m_right(std::move(right)) {}

    bool operator()(const Log& log) const override {
        return (*m_left)(log) && (*m_right)(log);
    }

private:
    std::unique_ptr<Predicate> m_left;
    std::unique_ptr<Predicate> m_right;
};

class OrPredicate : public Predicate {
public:
    OrPredicate(std::unique_ptr<Predicate> left, std::unique_ptr<Predicate> right)
        : m_left(std::move(left)), m_right(std::move(right)) {}

    bool operator()(const Log& log) const override {
        return (*m_left)(log) || (*m_right)(log);
    }

private:
    std::unique_ptr<Predicate> m_left;
    std::unique_ptr<Predicate> m_right;
};

class NotPredicate : public Predicate {
public:
    NotPredicate(std::unique_ptr<Predicate> operand)
        : m_operand(std::move(operand)) {}

    bool operator()(const Log& log) const override {
        return !(*m_operand)(log);
    }

private:
    std::unique_ptr<Predicate> m_operand;
}; 