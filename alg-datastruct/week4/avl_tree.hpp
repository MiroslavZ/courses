#ifndef _COURSES_AVL_TREE_HPP_
#define _COURSES_AVL_TREE_HPP_

#include <algorithm>
#include <memory>

template <typename T>
struct _avl_node {
  explicit _avl_node(T key) : key_{key} {}

  _avl_node *left_child_{nullptr};
  _avl_node *right_child_{nullptr};
  T key_;
  unsigned height_{1};
};

template <typename T>
class AVL_Tree {
 public:
  using iterator = _avl_node<T> *;

  AVL_Tree() : root_{nullptr} {}

  ~AVL_Tree() {

  }

  iterator Insert(const T &key)
  {
    if (root_ != nullptr) {
      iterator hint = root_;
    }
    else {
      root_ = new _avl_node<T>(key);

      return root_;
    }
  }

  iterator Insert(iterator hint, const T &key)
  {
    if (hint == nullptr) {
      return new _avl_node<T>(key);
    }

    if (key < hint->key_) {
      hint->left_child_ = Insert(hint->left_child_, key);
    }
    else {
      hint->right_child_ = Insert(hint->right_child_, key);
    }

    return Balance(hint);
  }

 protected:
  // balance
  iterator Balance(iterator node)
  {
    const auto height_diff = BalanceFactor(node);

    if (height_diff > 1) {
      // right-heavy tree
      const auto right_subtree_balance = BalanceFactor(node->right_child_);

      if (right_subtree_balance < 0) {
        // left-heavy right subtree - big left rotation
        node->right_child_ = RightRotation(node->right_child_);
      }
      // small left rotation
      return LeftRotation(node);
    }
    else if (height_diff < -1) {
      // left-heavy tree
      const auto left_subtree_balance = BalanceFactor(node->left_child_);

      if (left_subtree_balance > 0) {
        // right-heavy left subtree - big right rotation
        node->left_child_ = LeftRotation(node->left_child_);
      }
      // small right rotation
      return RightRotation(node);
    }
    // do not need to do balancing here
    return node;
  }

  iterator RightRotation(iterator node) {
    iterator left_child = node->left_child_;
    node->left_child_ = left_child->right_child_;
    left_child->right_child_ = node;
    FixHeight(left_child);
    FixHeight(node);

    return left_child;
  }

  iterator LeftRotation(iterator node) {
    iterator right_child = node->right_child_;
    node->right_child_ = right_child->left_child_;
    right_child->left_child_ = node;
    FixHeight(right_child);
    FixHeight(node);

    return right_child;
  }

  iterator FindMin(iterator node) {
    return (node->left_child_) ? FindMin(node->left_child_) : node;
  }

  unsigned GetNodeHeight(iterator node) {
    return (node != nullptr) ? node->height_ : 0;
  }

  int BalanceFactor(iterator node) {
    const auto left_subtree_h = GetNodeHeight(node->left_child_);
    const auto right_subtree_h = GetNodeHeight(node->right_child_);

    return static_cast<int>(right_subtree_h - left_subtree_h);
  }

  void FixHeight(iterator node) {
    const auto left_subtree_h = GetNodeHeight(node->left_child_);
    const auto right_subtree_h = GetNodeHeight(node->right_child_);

    node->height_ = std::max(left_subtree_h, right_subtree_h) + 1;
  }
  // rotation
 private:
  _avl_node<T> *root_;
};

#endif  // _COURSES_AVL_TREE_HPP_
