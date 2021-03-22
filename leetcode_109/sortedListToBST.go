package main

type ListNode struct {
    Val int
    Next *ListNode
}

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func buildBST(nums []int, s int, e int) *TreeNode {
    if s > e {
        return nil
    }

    mid  := s + (e - s) / 2
    root := &TreeNode{}

    root.Val = nums[mid]

    root.Left = buildBST(nums, s, mid - 1)
    root.Right = buildBST(nums, mid + 1, e)

    return root
}

func sortedListToBST(head *ListNode) *TreeNode {
    nums := []int{}
    t := head
    for t != nil {
        nums = append(nums, t.Val)
        t = t.Next
    }

    return buildBST(nums, 0, len(nums) - 1)
}
