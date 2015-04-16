# Jellyfish

A ruby gem wrapper for cjellyfish: https://github.com/sunlightlabs/jellyfish , for doing approximate and phonetic matching of strings.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'jellyfish'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install jellyfish

## Usage

```ruby
require 'jellyfish'

# include in your class
include JellyFish

levenshtein_distance('jellyfish', 'smellyfish')
jaro_distance('jellyfish', 'smellyfish')
metaphone('Jellyfish')

# stemmer
stemmer = JellyFish::Stemmer.new
# or after included
stemmer = Stemmer.new

stemmer.stem "riding"
stemmer.stem "fish"

```

## Contributing

1. Fork it ( https://github.com/gihnius/jellyfish/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
