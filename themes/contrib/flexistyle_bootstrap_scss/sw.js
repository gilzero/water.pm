// This code executes in its own worker or thread
self.addEventListener("install", event => {
  // console.log("Service worker installed");
  self.skipWaiting();
});
self.addEventListener("activate", event => {
  // console.log("Service worker activated");
  event.waitUntil(clients.claim());
});
