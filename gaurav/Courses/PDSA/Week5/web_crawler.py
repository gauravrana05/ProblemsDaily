import requests
from bs4 import BeautifulSoup
from collections import deque
import urllib.parse

class WebCrawler:
    def __init__(self, base_url, max_depth=2):
        self.base_url = base_url
        self.max_depth = max_depth
        self.visited = set()  # Set to keep track of visited URLs
        self.queue = deque([(base_url, 0)])  # Queue of URLs to visit, along with their depth

    def get_links(self, url):
        """Fetch the page content and return all unique links found on the page."""
        try:
            response = requests.get(url)
            response.raise_for_status()  # Check if the request was successful
            soup = BeautifulSoup(response.text, 'html.parser')

            links = set()
            for a_tag in soup.find_all('a', href=True):  # Find all <a> tags with href attribute
                href = a_tag['href']
                # Convert relative URLs to absolute URLs
                full_url = urllib.parse.urljoin(url, href)
                links.add(full_url)
            return links
        except requests.RequestException:
            return set()  # Return empty set if request fails

    def crawl(self):
        """Start the crawling process using BFS."""
        while self.queue:
            current_url, depth = self.queue.popleft()

            # Skip if the URL has already been visited
            if current_url in self.visited:
                continue

            # Mark the URL as visited
            self.visited.add(current_url)

            # If we've reached the maximum depth, stop further exploration
            if depth >= self.max_depth:
                continue

            # Get links from the current page
            links = self.get_links(current_url)
            print(f"Depth {depth}: {current_url} -> Found {len(links)} links")

            # Add the unvisited links to the queue with incremented depth
            for link in links:
                if link not in self.visited:
                    self.queue.append((link, depth + 1))

            # Optionally print all visited URLs at the end of the crawl
            if not self.queue:  # If queue is empty, all reachable pages have been visited
                print("\nCrawling completed. Visited URLs:")
                for url in self.visited:
                    print(url)

# Example usage
if __name__ == "__main__":
    start_url = "http://learning.sqroot.site"  # Replace with your starting URL
    crawler = WebCrawler(start_url, max_depth=2)  # Set max_depth as per requirement
    crawler.crawl()
