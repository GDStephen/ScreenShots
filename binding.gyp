{
  "targets": [
    {
      "target_name": "screenshots",
      "sources": [ "screenshots.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}