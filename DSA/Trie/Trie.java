public class Trie {
  public static int ALPHABET_SIZE = 26;

  private class Node {
    private char value;
    private HashMap<Character, Node> children = new HashMap<>();
    private boolean isEndOfWord;

    public Node(char value) {
      this.value = value;
    }

    @Override
    public String toString() {
      return "value=" + value;
    }

    public boolean hasChild(char ch) {
      return children.containsKey(ch);
    }

    public void addChild(char ch) {
      children.put(ch, new Node(ch));
    }

    public Node getChild(char ch) {
      return children.get(ch);
    }

    public Node[] getChildren() {
      return children.values().toArray(new Node[0]);
    }

    public boolean hasChildren() {
      return !children.isEmpty();
    }

    public void removeChild(char ch) {
      children.remove(ch);
    }
  }

  private Node root = new Node(' ');

  public void insert(String word) {
    var current = root;
    for (var ch : word.toCharArray()) {
      if (!current.hasChild(ch))
        current.addChild(ch);
      current = current.getChild(ch);
    }
    current.isEndOfWord = true;
  }

  public boolean contains(String word) {
    if (word == null)
      return false;

    var current = root;
    for (var ch : word.toCharArray()) {
      if (!current.hasChild(ch))
        return false;
      current = current.getChild(ch);
    }
    return current.isEndOfWord;
  }

  public void traverse() {
    traverse(root);
  }

  private void traverse(Node root) {
    for (var child : root.getChildren())
      traverse(child);

    // Post-order: visit the root last
    System.out.println(root.value);
  }

  public void remove(String word) {
    if (word == null)
      return;

    remove(root, word, 0);
  }

  private void remove(Node root, String word, int index) {
    if (index == word.length()) {
      root.isEndOfWord = false;
      return;
    }

    var ch = word.charAt(index);
    var child = root.getChild(ch);
    if (child == null)
      return;

    remove(child, word, index + 1);

    if (!child.hasChildren() && !child.isEndOfWord)
      root.removeChild(ch);
  }

  public List<String> findWords(String prefix) {
    List<String> words = new ArrayList<>();
    var lastNode = findLastNodeOf(prefix);
    findWords(lastNode, prefix, words);

    return words;
  }

  private void findWords(Node root, String prefix, List<String> words) {
    if (root == null)
      return;

    if (root.isEndOfWord)
      words.add(prefix);

    for (var child : root.getChildren())
      findWords(child, prefix + child.value, words);
  }

  private Node findLastNodeOf(String prefix) {
    if (prefix == null)
      return null;

    var current = root;
    for (var ch : prefix.toCharArray()) {
      var child = current.getChild(ch);
      if (child == null)
        return null;
      current = child;
    }
    return current;
  }

  public boolean containsRecursive(String word) {
    if (word == null)
      return false;

    return containsRecursive(root, word, 0);
  }

  private boolean containsRecursive(Node root, String word, int index) {
    // Base condition
    if (index == word.length())
      return root.isEndOfWord;

    if (root == null)
      return false;

    var ch = word.charAt(index);
    var child = root.getChild(ch);
    if (child == null)
      return false;

    return containsRecursive(child, word, index + 1);
  }

  public int countWords() {
    return countWords(root);
  }

  private int countWords(Node root) {
    var total = 0;

    if (root.isEndOfWord)
      total++;

    for (var child : root.getChildren())
      total += countWords(child);

    return total;
  }

  public void printWords() {
    printWords(root, "");
  }

  private void printWords(Node root, String word) {
    if (root.isEndOfWord)
      System.out.println(word);

    for (var child : root.getChildren())
      printWords(child, word + child.value);
  }

  // We add these words to a trie and walk down
  // the trie. If a node has more than one child,
  // that's where these words deviate. Try this
  // with "can", "canada", "care" and "cab". You'll
  // see that these words deviate after "ca".
  //
  // So, we keep walking down the tree as long as
  // the current node has only one child.
  //
  // One edge cases we need to count is when two
  // words are in the same branch and don't deviate.
  // For example "can" and "canada". In this case,
  // we keep walking down to the end because every
  // node (except the last node) has only one child.
  // But the longest common prefix here should be
  // "can", not "canada". So, we should find the
  // shortest word in the list first. The maximum
  // number of characters we can include in the
  // prefix should be equal to the length of the
  // shortest word.


  public static String longestCommonPrefix(String[] words) {
    if (words == null)
      return "";

    var trie = new Trie();
    for (var word : words)
      trie.insert(word);

    var prefix = new StringBuffer();
    var maxChars = getShortest(words).length();
    var current = trie.root;
    while (prefix.length() < maxChars) {
      var children = current.getChildren();
      if (children.length != 1)
        break;
      current = children[0];
      prefix.append(current.value);
    }

    return prefix.toString();
  }

  private static String getShortest(String[] words) {
    if (words == null || words.length == 0)
      return "";

    var shortest = words[0];
    for (var i = 1; i < words.length; i++) {
      if (words[i].length() < shortest.length())
        shortest = words[i];
    }

    return shortest;
  }
}
