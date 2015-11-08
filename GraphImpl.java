import java.util.*;
import java.io.*;

public class GraphImpl {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		Graph graph = new Graph(Integer.parseInt(reader.readLine()), reader.readLine().equalsIgnoreCase("1")?true:false);
		String s;
		do
		{
			s = reader.readLine();
			String[] a = s.split(" ");
			if(s.equalsIgnoreCase("stop"))
				continue;
			graph.addEdge(Integer.parseInt(a[0]), Integer.parseInt(a[1]));
		}while(!s.equalsIgnoreCase("stop"));
		System.out.println("----------------------------\n");
		graph.printGraph();
		graph.BFS(Integer.parseInt(reader.readLine().trim()));
	}
}

class Queue
{
	ArrayList<Integer> queue;

	public Queue()
	{
		queue = new ArrayList<Integer>();		
	}

	public void enqueue(int num)
	{
		queue.add(num);
	}

	public int dequeue()
	{
		if(queue.size() == 0)
			return -1;		
		
		int temp = queue.get(0);
		queue.remove(0);
		return temp;
	}
}

class Graph
{
	private AdjacencyList list;

	public Graph(int count, boolean undirected)
	{
		list = new AdjacencyList(count, undirected);
	}

	public void addEdge(int source, int dest)
	{
		list.setEdge(source, dest);
	}

	public void printGraph()
	{
		list.print();
	}

	public void BFS(int src)
	{
		Queue queue = new Queue();
		queue.enqueue(src);
		AdjacencyNode[] nodes = list.getList();
		int temp = queue.dequeue();
				
		nodes[src].setDepth(0);

		while(temp != -1 && !nodes[temp].isVisited())
		{
			System.out.println(temp + " : depth=" + nodes[temp].getDepth());
			nodes[temp].setVisited(true);
			AdjacencyNode t = nodes[temp].getNext();
			while(t != null)
			{
				queue.enqueue(t.getNum());
				nodes[t.getNum()].setDepth(nodes[temp].getDepth() + 1);
				System.out.println(t.getNum() + " " + nodes[t.getNum()].getDepth());
				t = t.getNext();
			}
			System.out.println();			
			temp = queue.dequeue();			
		}
	}
}

class AdjacencyList
{
	private AdjacencyNode[] list;
	private int count;
	private boolean undirected;

	public AdjacencyList(int count, boolean undirected)
	{
		this.undirected = undirected;
		this.count = count;
		list = new AdjacencyNode[count];
		for(int i = 0; i < count; i++)
		{
			list[i] = new AdjacencyNode(i);
		}		
	}

	protected AdjacencyNode[] getList()
	{
		return list;
	}

	public void setEdge(int source, int dest)
	{
		list[source].setNext(new AdjacencyNode(dest));
		if(undirected)
		{
			list[dest].setNext(new AdjacencyNode(source));
		}
	}

	public int getCount()
	{
		return count;
	}

	public boolean isUndirected()
	{
		return undirected;
	}

	public void print()
	{
		for(AdjacencyNode node : list)
		{
			System.out.println();
			while(node.getNext() != null)
			{
				System.out.print(node.getNum() + "->");
				node = node.getNext();
			}
			System.out.print(node.getNum());
		}
		System.out.println();
	}
}

class AdjacencyNode
{
	private AdjacencyNode next = null;
	private int number = 0, depth = -1;
	private boolean visited = false;

	public AdjacencyNode(int number)
	{
		this.number = number;
	}

	public void setDepth(int depth)
	{
		this.depth = depth;
	}

	public int getDepth()
	{
		return depth;
	}

	public boolean isVisited()
	{
		return visited;
	}

	public void setVisited(boolean visited)
	{
		this.visited = visited;
	}

	public void setNext(AdjacencyNode next)
	{
		if(this.next == null)
			this.next = next;
		else
		{
			AdjacencyNode temp = this.next;
			while(temp.next != null)
			{
				temp = temp.getNext();
			}
			temp.next = next;
		}
	}

	public int getNum()
	{
		return number;
	}

	public AdjacencyNode getNext()
	{
		return next;
	}
}