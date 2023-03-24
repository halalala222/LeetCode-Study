// import java.util.ArrayList;
// import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;;

/*
 * @lc app=leetcode.cn id=1032 lang=java
 *
 * [1032] 字符流
 */
/**
 * 使用 普通 hash 超时了，明天来研究一下。
 */
// // @lc code=start
// class StreamChecker {
// HashSet<String> words;
// ArrayList<Character> charIO;

// public StreamChecker(String[] words) {
// this.words = new HashSet<String>();
// this.charIO = new ArrayList<Character>();
// for (String word : words) {
// this.words.add(word);
// }

// }

// public boolean query(char letter) {
// charIO.add(letter);
// String charSuffix = "";
// for (int i = charIO.size() - 1; i >= 0; i--) {
// charSuffix = charIO.get(i) + charSuffix;
// System.out.println(charSuffix);
// if (words.contains(charSuffix)) {
// return true;
// }
// }
// return false;
// }
// }
class StreamChecker {
    TrieNode root;
    TrieNode temp;

    public StreamChecker(String[] words) {
        root = new TrieNode();
        for (String word : words) {
            TrieNode cur = root;
            for (int i = 0; i < word.length(); i++) {
                int index = word.charAt(i) - 'a';
                if (cur.getChild(index) == null) {
                    cur.setChild(index, new TrieNode());
                }
                cur = cur.getChild(index);
            }
            cur.setIsEnd(true);
        }
        root.setFail(root);
        Queue<TrieNode> q = new LinkedList<>();
        for (int i = 0; i < 26; i++) {
            if (root.getChild(i) != null) {
                root.getChild(i).setFail(root);
                q.add(root.getChild(i));
            } else {
                root.setChild(i, root);
            }
        }
        while (!q.isEmpty()) {
            TrieNode node = q.poll();
            node.setIsEnd(node.getIsEnd() || node.getFail().getIsEnd());
            for (int i = 0; i < 26; i++) {
                if (node.getChild(i) != null) {
                    node.getChild(i).setFail(node.getFail().getChild(i));
                    q.offer(node.getChild(i));
                } else {
                    node.setChild(i, node.getFail().getChild(i));
                }
            }
        }

        temp = root;
    }

    public boolean query(char letter) {
        temp = temp.getChild(letter - 'a');
        return temp.getIsEnd();
    }
}

class TrieNode {
    TrieNode[] children;
    boolean isEnd;
    TrieNode fail;

    public TrieNode() {
        children = new TrieNode[26];
    }

    public TrieNode getChild(int index) {
        return children[index];
    }

    public void setChild(int index, TrieNode node) {
        children[index] = node;
    }

    public boolean getIsEnd() {
        return isEnd;
    }

    public void setIsEnd(boolean b) {
        isEnd = b;
    }

    public TrieNode getFail() {
        return fail;
    }

    public void setFail(TrieNode node) {
        fail = node;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
// @lc code=end
