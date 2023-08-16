class Solution {
    public List<Integer> preorderTraversal(TreeNode root) 
    {
        TreeNode currentNode = root;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        List<Integer> result = new ArrayList<Integer>();
        while(!stack.isEmpty() || currentNode!=null)
        {
            if(currentNode!=null) {
                result.add(currentNode.val);
                stack.push(currentNode);
                currentNode = currentNode.left;
            } else {
                currentNode = stack.pop();
                currentNode = currentNode.right;
            }
        }
        return result;
    }
}
TreeNode currentNode = root;
Stack<TreeNode> stack = new Stack<TreeNode>();
List<Integer> result = new ArrayList<Integer>();

while(!stack.isEmpty() || currentNode!=null)
  if(currentNode!=null){
    result.add(currentNode.val);
    stack.push(currentNode);
    currentNode = currentNode.left;
} else {
    currentNode = stack.pop();
    currentNode = currentNode.right;
}
